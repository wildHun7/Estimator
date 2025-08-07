#include "item.h"

namespace Items
{
    void Item::setNameItem(std::string& name)
    {
       this->m_item_name = name;
    }

    std::string Item::getName() const
    {
        return this->m_item_name;
    }
}


