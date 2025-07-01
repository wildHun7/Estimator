#include "section_table_model.h"

namespace GUI
{
    SectionTableModel::SectionTableModel(Manager::SectionManager& manager, QObject* parent)
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
                case 0: return "Item";
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

        if(itemIndex == -1) // Section
        {
            if(column == 0)
                return QString::fromStdString(m_manager.getSections()[sectionIndex]->getName());
        return QVariant();
        } else
            { // Item
            const auto& section = m_manager.getSections()[sectionIndex];
            const auto& itemsMap = section->getItems();
            auto it = std::next(itemsMap.begin(), itemIndex);
            const auto& itemPtr = it->first;
            int itemCount = it->second;

            if(itemPtr){
                const auto& item = *itemPtr;

                switch(column) {
                case 0: return QString::fromStdString(item.getName());
                case 1: return itemCount;
                case 2: return item.calcCosts();
                case 3: return item.calcCosts() * itemCount;
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
        for(const auto& section: m_manager.getSections())
        {
            count += 1;
            count += section->getItems().size();
        }
        return count;

    }

    std::pair<int, int> SectionTableModel::indexOfSectionOrItem(int row) const
    {
        int current_row = 0;

        for(size_t section_index = 0; section_index < m_manager.getSections().size(); ++section_index)
        {
            if(current_row == row)
                return {static_cast<int>(section_index), -1};

            current_row++;

            for(size_t item_index = 0; item_index < m_manager.getSections()[section_index]->getItems().size(); ++item_index)
            {
                if(current_row == row)
                    return {static_cast<int>(section_index), static_cast<int>(item_index)};
                ++current_row;
            }
        }
        return {-1, -1};
    }
}
