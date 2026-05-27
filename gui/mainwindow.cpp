#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "section_type1.h"

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

    void MainWindow::on_addSectionButton_clicked()
    {
        bool ok;
        QString name = QInputDialog::getText(this, "Add section", "Section name:", QLineEdit::Normal, "", &ok);

        if(ok && !name.trimmed().isEmpty())
        {
            try{
                auto section = std::make_unique<Sections::SectionType1>(name.toStdString());
                m_model->getManager()->addSection(std::move(section));
                m_model->refresh();
            } catch (std::exception& e) {
                QMessageBox::warning(this, "Error", QString("Failed to add the section:\n") + e.what());
            }
        }
    }

    void MainWindow::on_addItemButton_clicked()
    {
        // 1. Select section

        QStringList section_list;
        for(const auto& section: m_model->getManager()->getSections())
        {
            section_list << QString::fromStdString(std::string(section->getName()));

            if (section_list.isEmpty()) {
                QMessageBox::information(this, "No section", "There are no sections available.");
                return;
            }
        }
        bool ok;
        QString chosen_section = QInputDialog::getItem(this, "Select Section", "Section:", section_list, 0, false, &ok);
        if(!ok || chosen_section.isEmpty())
            return;

        // 2. Get item data

        QString item_name = QInputDialog::getText(this, "Add Item", "Name:", QLineEdit::Normal, "", &ok);
        if (!ok || item_name.trimmed().isEmpty())
            return;

        int quantity = QInputDialog::getInt(this, "Add Item", "Quantity:", 1, 1, 1000, 1, &ok);
        if (!ok)
            return;

        int cost = QInputDialog::getInt(this, "Dodaj przedmiot", "Cena:", 1, 1, 100000, 1, &ok);
        if (!ok)
            return;

        try {
        // 3. Create item

            auto item = std::make_unique<Items::ItemType1>(item_name.toStdString(), cost);
            auto section = m_model->getManager()->findSection(chosen_section.toStdString());
            if (section)
            {
                section->addItem(std::move(item), quantity);
                m_model->refresh();
            } else {
                QMessageBox::warning(this, "Error", "Section not found.");
            }
        }   catch(const std::exception& e) {
            QMessageBox::warning(this, "Error", QString("Failed to add the item:\n") + e.what());
        }
    }

    void MainWindow::on_removeSectionButton_clicked()
    {
        // 1. Preparing section list

        QStringList section_list;
        for(const auto& section: m_model->getManager()->getSections())
            section_list << QString::fromStdString(std::string(section->getName()));

        if(section_list.empty())
        {
            QMessageBox::information(this, "No Sections", "There are no sections to remove.");
            return;
        }

        // 2. Select section for removal

        bool ok;
        QString chosen_section = QInputDialog::getItem(this, "Remove Section", "Select a section to remove:", section_list, 0, false, &ok);
        if(!ok || chosen_section.isEmpty())
            return;

        if (m_model->getManager()->removeSection(chosen_section.toStdString()))
        {
            m_model->refresh();
        } else {
            QMessageBox::warning(this, "Error", "Failed to remove the section");
        }
    }

    void MainWindow::on_removeItemButton_clicked()
    {
        // 1. Preparing section list

        QStringList section_list;
        for(const auto& section: m_model->getManager()->getSections())
            section_list << QString::fromStdString(std::string(section->getName()));

        if(section_list.isEmpty())
        {
            QMessageBox::information(this, "No Sections", "There are no sections available.");
            return;
        }

        bool ok;
        QString chosen_section = QInputDialog::getItem(this, "Select Section", "Choose a section:", section_list, 0, false, &ok);
        if(!ok || chosen_section.isEmpty())
            return;

        // 2. Item selection

        auto section = m_model->getManager()->findSection(chosen_section.toStdString());
        QStringList item_list;
        for(const auto&[name, pair]: section->getItems())
            item_list << QString::fromStdString(name);

        if(item_list.isEmpty())
        {
            QMessageBox::information(this, "No Items", "There are no items in this section.");
            return;
        }

        QString chosen_item;
        chosen_item = QInputDialog::getItem(this, "Select Item", "Choose an item to remove:", item_list, 0, false, &ok);
        if(!ok || chosen_item.isEmpty())
            return;

        if (section->removeItem(chosen_item.toStdString()))
        {
            m_model->refresh();
        } else {
            QMessageBox::warning(this, "Error", "Failed to remove the item.");
        }
    }

    void MainWindow::on_actionSave_triggered()
    {
        if (m_model->getManager()->saveToDatabase()) {
            QMessageBox::information(this, "Saved", "Data saved successfully");
        } else {
            QMessageBox::warning(this, "Error", "Failed to save data!");
        }
    }

    void MainWindow::on_actionLoad_triggered()
    {
        if (m_model->getManager()->loadFromDatabase()) {
            m_model->refresh();  // Odśwież widok!
            QMessageBox::information(this, "Loaded", "Data loaded successfully!");
        } else {
            QMessageBox::warning(this, "Error", "Failed to load data!");
        }
    }
}
