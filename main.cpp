#include "mainwindow.h"
#include <QApplication>
#include "item.h"
#include "itemtype1.h"
#include "itemtype2.h"
#include "section.h"
#include "sectiontype1.h"
#include "sectiontype2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //Items::Item* c = new Items::ItemType1(2);
    //delete c;
    return a.exec();
}
