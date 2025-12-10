#include "database_handler.h"

namespace Database
{

    DatabaseHandler::DatabaseHandler(const QString& db_path) : m_db_path(db_path)
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName(m_db_path);
    }

    DatabaseHandler::~DatabaseHandler()
    {
        close();
    }

    bool DatabaseHandler::open()
    {
        if(!m_db.open())
        {
            qWarning() << "Failed to open database" << m_db.lastError().text();
            return false;
        }
        return true;
    }

    void DatabaseHandler::close()
    {
        if(m_db.isOpen())
            m_db.close();
    }

    // CRUD operations

    bool DatabaseHandler::init()
    {
        QSqlQuery query;

        // --- Create tables if they don't exist ---

        return query.exec(
            "CREATE TABLE IF NOT EXISTS sections ("
            "name TEXT PRIMARY KEY)"
        ) &&
        query.exec(
            "CREATE TABLE IF NOT EXISTS items ("
            "section_name TEXT,"
            "item_name TEXT,"
            "cost INTEGER,"
            "quantity INTEGER,"
            "PRIMARY KEY(section_name, item_name),"
            "FOREIGN KEY(section_name) REFERENCES sections(name) ON DELETE CASCADE)"
        );
    }

    bool DatabaseHandler::saveSections(Sections::Section& section)
    {
        QSqlQuery query;

        query.prepare("INSERT OR IGNORE INTO sections (name) VALUES (:name)");
        query.bindValue(":name", QString::fromStdString(section.getName()));

        return query.exec();
    }

    bool DatabaseHandler::saveItem(const std::string& section_name, const std::string& item_name, int cost, int quantity)
    {
        QSqlQuery query;
        query.prepare("INSERT OR REPLACE INTO items (section_name, item_name, cost, quantity) "
                          "VALUES (:section, :item, :cost, :qty)");
        query.bindValue(":section", QString::fromStdString(section_name));
        query.bindValue(":item", QString::fromStdString(item_name));
        query.bindValue(":cost", cost);
        query.bindValue(":qty", quantity);
        return query.exec();
    }

    std::vector<std::unique_ptr<Sections::Section>> DatabaseHandler::loadSections()
    {
        std::vector<std::unique_ptr<Sections::Section>> sections;
        QSqlQuery query;
        query.prepare("SELECT name FROM sections");

        if(!query.exec())
        {
            qWarning() << "DB failed to load sections:" << query.lastError().text();
            return sections;
        }

        while(query.next())
        {
            QString section_name = query.value(0).toString();

            auto section = std::make_unique<Sections::SectionType1>(section_name.toStdString());

            QSqlQuery item_query;
            item_query.prepare(
                "SELECT item_name, cost, quantity "
                "FROM items WHERE section_name = :sec"
            );

            item_query.bindValue(":sec", section_name);

            if(!item_query.exec())
            {
                qWarning() << "DB failed to load items for section" << section_name << ":" <<item_query.lastError().text();
                continue;
            }

            while(item_query.next())
            {
                QString item_name = item_query.value(0).toString();
                int cost         = item_query.value(1).toInt();
                int quantity     = item_query.value(2).toInt();

                auto item = std::make_unique<Items::ItemType1>(item_name.toStdString(), cost);

                section->addItem(std::move(item), quantity);
            }
            sections.push_back(std::move(section));
        }

        return sections;
    }

    bool DatabaseHandler::removeSections(const std::string& section_name)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM sections WHERE name = :name");
        query.bindValue(":name", QString::fromStdString(section_name));
        return query.exec();
    }

    bool DatabaseHandler::removeItem(const std::string& section_name, const std::string& item_name)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM items WHERE section_name = :section AND item_name = :item");
        query.bindValue(":section", QString::fromStdString(section_name));
        query.bindValue(":item", QString::fromStdString(item_name));
        return query.exec();
    }
}
