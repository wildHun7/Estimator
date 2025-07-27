#include "section_table_model.h"

namespace GUI
{
    SectionTableModel::SectionTableModel(Manager::SectionManager* manager, QObject* parent)
    : m_manager(manager), QAbstractTableModel(parent)
    {

    }

    int SectionTableModel::rowCount(const QModelIndex& parent) const
    {
        Q_UNUSED(parent);
        return totalRowCount();
    }

    int SectionTableModel::columnCount(const QModelIndex& parent) const
    {
        Q_UNUSED(parent);
        return 4; // Item Name, Quantity, Price, Total Price
    }

    QVariant SectionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
    {
        if(role != Qt::DisplayRole)
            return QVariant();

        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0: return "Item/Section";
                case 1: return "Quantity";
                case 2: return "Price";
                case 3: return "Total Price";
                default: return QVariant();
            }
        }

        else if(orientation == Qt::Vertical)
            return section + 1;

        return QVariant();
    }

    QVariant SectionTableModel::data(const QModelIndex& index, int role) const
    {
        if(!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        int row = index.row();
        int column = index.column();

        auto [sectionIndex, itemIndex] = indexOfSectionOrItem(row);
        const auto& section = m_manager->getSections()[sectionIndex];

        if(itemIndex == -1) // Section row
        {
            if(column == 0)
                return QString::fromStdString(section->getName());
            return QVariant();
        }
        else // Item row
            {
            const auto& itemsMap = section->getItems();
            auto it = std::next(itemsMap.begin(), itemIndex);
            const auto& itemPtr = it->second.first;
            int quantity = it->second.second;

            if(itemPtr){
                const auto& item = *itemPtr;

                switch(column) {
                case 0: return QString::fromStdString(item.getName());
                case 1: return quantity;
                case 2: return item.calcCosts();
                case 3: return item.calcCosts() * quantity;
                }
            }
        }

        return QVariant();
    }

    // Data update

    void SectionTableModel::refresh()
    {
        beginResetModel();
        endResetModel();
    }

    // Private helper functions

    int SectionTableModel::totalRowCount() const
    {
        int count = 0;
        for(const auto& section: m_manager->getSections())
        {
            count += 1;
            count += section->getItems().size();
        }
        return count;

    }

    std::pair<int, int> SectionTableModel::indexOfSectionOrItem(int row) const
    {
        int current_row = 0;

        for(size_t section_index = 0; section_index < m_manager->getSections().size(); ++section_index)
        {
            if(current_row == row)
                return {static_cast<int>(section_index), -1};

            current_row++;

            int item_index = 0;
            for(const auto& [itemPtr, itemData]: m_manager->getSections()[section_index]->getItems())
            {
                if(current_row == row)
                    return {static_cast<int>(section_index), item_index};
                ++current_row;
                ++item_index;
            }
        }
        return {-1, -1};
    }
}
