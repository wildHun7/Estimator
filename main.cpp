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
    QApplication a(argc, argv);
    auto* manager = new Manager::SectionManager();
    auto* model = new GUI::SectionTableModel(manager);
    GUI::MainWindow w(model);
    w.show();

    return a.exec();
}
