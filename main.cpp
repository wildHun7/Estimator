#include "section_manager.h"
#include "mainwindow.h"
#include "section_table_model.h"
#include "database_handler.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto db = std::make_unique<Database::DatabaseHandler>("estimator.db");

    if (!db->open() || !db->init()) {
        qWarning() << "Failed to initialize database!";
    }

    auto manager = std::make_unique<Manager::SectionManager>(db.get());
    auto model = std::make_unique<GUI::SectionTableModel>(manager.get());

    GUI::MainWindow window(model.get());
    window.show();

    return app.exec();
}
