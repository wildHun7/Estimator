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
<<<<<<< Updated upstream
        SectionTableModel(Manager::SectionManager& _manager, QObject* _parrent = nullptr);
=======
        SectionTableModel(Manager::SectionManager& manager, QObject* parent = nullptr);

        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        int columnCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;
        QVariant data(const QModelIndex& index, int role) const;

        // Data update
        void refresh();
>>>>>>> Stashed changes

    private:
        Manager::SectionManager& m_manager;

<<<<<<< Updated upstream
=======
        // Private helper functions
        int totalRowCount() const;
        std::pair<int, int> indexOfSectionAndItem(int row) const;
>>>>>>> Stashed changes
    };
}
#endif // SECTION_TABLE_MODEL_H
