#ifndef SECTION_TABLE_MODEL_H
#define SECTION_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QPair>
#include <QString>
#include "section_manager.h"

namespace GUI
{
    class SectionTableModel : public QAbstractTableModel
    {
        Q_OBJECT
    public:
        SectionTableModel(Manager::SectionManager& _manager, QObject* _parent = nullptr);

        int rowCount(const QModelIndex& _parent = QModelIndex()) const override;
        int columnCount(const QModelIndex& _parent = QModelIndex()) const override;
        QVariant headerData(int _section, Qt::Orientation _orientation, int _role) const;
        QVariant data(const QModelIndex& _index, int _role) const;

        // Data update
        void refresh();

    private:
        Manager::SectionManager& m_manager;
        QVector<QPair<QString, QVector<std::weak_ptr<Items::Item>>>> m_table_data;

        // Private helper functions
        void rebuildTableData();
        int totalRowCount() const;
    };
}
#endif // SECTION_TABLE_MODEL_H
