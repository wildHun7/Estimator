#include "section_table_model.h"

namespace GUI
{
    SectionTableModel::SectionTableModel(Manager::SectionManager& _manager, QObject* _parent)
    : m_manager(_manager), QAbstractTableModel(_parent)
    {
        rebuildTableData();
    }

    SectionTableModel::rowCount(const QModelIndex& _parent) const
    {
        Q_UNUSED(_parent);
        return totalRowCount();
    }

    SectionTableModel::columnCount(const QModelIndex& _parent) const
    {
        Q_UNUSED(_parent);
        return 4; // Item Name, Quantity, Price, Total Price
    }

    QVariant SectionTableModel::headerData(int _section, Qt::Orientation _orientation, int _role) const
    {
        if(_role != Qt::DisplayRole)
            return QVariant();

        if(_orientation = Qt::Horizontal)
        {
            switch(_section)
            {
                case 0: return "Item";
                case 1: return "Quantity";
                case 2: return "Price";
                case 3: return "Total Price";
                default: return QVariant();
            }
        }

        else if(_orientation = Qt::Vertical)
            return _section + 1;

        return QVariant();
    }

    QVariant SectionTableModel::data(const QModelIndex& _index, int _role) const
    {
        if(!_index.isValid() || _role != Qt::DisplayRole)
            return QVariant();

        int _row = _index.row();
        int _column = _index.column();

        int _current_row = 0;

        for(const auto& _qpair : m_table_data)
        {
            if(_current_row = _row)
            {
                if(_column = 0)
                    return _qpair.first; // Section Name
                return QVariant();
            }
            _current_row++;

            for(const auto& _weak_item: _qpair.second)
            {
                if(_current_row == _row && _weak_item.lock())
                {
                    auto _item = _weak_item.lock();
                    switch(_column)
                    {
                        case 1: return QString::fromStdString(_item->getName());
                        //case 2:
                        case 3: return _item->calcCosts();
                        //case 4: return QString::fromStdString(_item->getName());
                    }
                }
            _current_row++;

            }
        }
        return QVariant();
    }

    // Data update

    void SectionTableModel::refresh()
    {
        beginResetModel();
        rebuildTableData();
        endResetModel();
    }

    // Private helper functions

    void SectionTableModel::rebuildTableData()
    {
        m_table_data.clear();

        // Iterating over sections from the manager's member vector
        for(const auto& _section: m_manager.getSections()) //
        {
            QVector<std::weak_ptr<Items::Item>> _items;

            //iterating over items from section's the member map
            for(const auto& [_itemPtr, _count]: _section->getItems())
            {
                _items.append(_itemPtr);
            }
        m_table_data.append(qMakePair(QString::fromStdString(_section->getName()), _items));
        }
    }

    int SectionTableModel::totalRowCount() const
    {
        int count = 0;
        for(const auto& [_section_name, _section_items]: m_table_data)
        {
            count += 1;
            count += _section_items.size();
        }
        return count;
    }
}
