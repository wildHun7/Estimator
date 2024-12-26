#include "item.h"

namespace Items {

    void Item::setNameItem(std::string& _name)
    {
       this->m_itemName = _name;
    }

    std::string Item::getName()
    {
        return this->m_itemName;
    }

}


