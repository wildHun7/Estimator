#include "item.h"

namespace Items {

    void Item::setNameItem(std::string& name)
    {
       this->m_itemName = name;
    }

    std::string Item::getName() const
    {
        return this->m_itemName;
    }

}


