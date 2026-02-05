#include "item.h"

namespace Items
{
    void Item::setNameItem(std::string_view name)
    {
        m_item_name = name;
    }

    std::string_view Item::getName() const noexcept
    {
        return m_item_name;
    }
}


