#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
};

} //namespace GUI

#endif // MAINWINDOW_H
