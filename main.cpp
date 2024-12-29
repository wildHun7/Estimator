#include "mainwindow.h"
#include <QApplication>
#include "item.h"
#include "item_type1.h"
#include "item_type2.h"
#include "section.h"
#include "section_type1.h"
#include "section_type2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //Items::Item* c = new Items::ItemType1(2);
    //delete c;
    return a.exec();
}
