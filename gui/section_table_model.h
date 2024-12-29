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
        SectionTableModel(Manager::SectionManager& _manager, QObject* _parrent = nullptr);

    private:
        Manager::SectionManager& m_manager;

    };
}
#endif // SECTION_TABLE_MODEL_H
