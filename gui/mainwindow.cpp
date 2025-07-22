#include "mainwindow.h"
#include "./ui_mainwindow.h"

namespace GUI
{
    MainWindow::MainWindow(SectionTableModel* model, QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
        , m_model(model)
    {
        ui->setupUi(this);
        ui->tableView->setModel(m_model);
    }

    MainWindow::~MainWindow()
    {
       delete ui;
    }

}
