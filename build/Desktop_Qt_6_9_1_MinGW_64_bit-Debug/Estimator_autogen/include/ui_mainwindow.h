/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *buttonLayout;
    QPushButton *addSectionButton;
    QPushButton *removeSectionButton;
    QPushButton *addItemButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 60, 521, 451));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(639, 160, 131, 161));
        buttonLayout = new QVBoxLayout(verticalLayoutWidget);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        addSectionButton = new QPushButton(verticalLayoutWidget);
        addSectionButton->setObjectName("addSectionButton");

        buttonLayout->addWidget(addSectionButton);

        removeSectionButton = new QPushButton(verticalLayoutWidget);
        removeSectionButton->setObjectName("removeSectionButton");

        buttonLayout->addWidget(removeSectionButton);

        addItemButton = new QPushButton(verticalLayoutWidget);
        addItemButton->setObjectName("addItemButton");

        buttonLayout->addWidget(addItemButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addSectionButton->setText(QCoreApplication::translate("MainWindow", "Add Section", nullptr));
        removeSectionButton->setText(QCoreApplication::translate("MainWindow", "Remove Section", nullptr));
        addItemButton->setText(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
