#include "section_table_model.h"

namespace GUI
{
    SectionTableModel::SectionTableModel(Manager::SectionManager& _manager, QObject* _parrent)
    : m_manager(_manager), QAbstractTableModel(_parrent)
    {

    }
}
