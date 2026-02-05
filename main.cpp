#include "mainwindow.h"
#include <QApplication>

/*
#include "item.h"
#include "item_type1.h"
#include "item_type2.h"
#include "section.h"
#include "section_type1.h"
#include "section_type2.h"
*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto manager = std::make_unique<Manager::SectionManager>();
    auto model = std::make_unique<GUI::SectionTableModel>(manager.get());

    GUI::MainWindow window(model.get());
    window.show();

    return app.exec();
}
