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
        SectionTableModel(Manager::SectionManager* manager, QObject* parent = nullptr);

        Manager::SectionManager* getManager() const;

        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
        QVariant data(const QModelIndex& index, int role) const override;

        // Data update
        void refresh();

    private:
        Manager::SectionManager* m_manager;

        // Private helper functions
        int totalRowCount() const;
        std::pair<int, int> indexOfSectionOrItem(int row) const;

    };
}
#endif // SECTION_TABLE_MODEL_H
