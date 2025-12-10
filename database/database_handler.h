#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <memory>
#include <vector>
#include "section.h"
#include "section_type1.h"

namespace Database
{

    class DatabaseHandler
    {
    public:
        DatabaseHandler(const QString& db_path);
        ~DatabaseHandler();

        bool open();
        void close();
        bool init();

        // CRUD operations
        bool saveSections(Sections::Section& section);
        bool saveItem(const std::string& section_name, const std::string& item_name, int cost, int quantity);

        std::vector<std::unique_ptr<Sections::Section>> loadSections();
        bool removeSections(const std::string& section_name);
        bool removeItem(const std::string& section_name, const std::string& item_name);

    private:
        QSqlDatabase m_db;
        QString m_db_path;
    };

}

#endif // DATABASE_HANDLER_H
