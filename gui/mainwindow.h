#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include "section_table_model.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

namespace GUI
{

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(SectionTableModel* model, QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow* ui;
        SectionTableModel* m_model;

    private slots:
        void on_addSectionButton_clicked();
        void on_addItemButton_clicked();
        void on_removeSectionButton_clicked();
        void on_removeItemButton_clicked();
    };

} //namespace GUI

#endif // MAINWINDOW_H
