#include "item.h"

namespace Items
{
    void Item::setNameItem(std::string_view name)
    {
        m_item_name = name;
    }

    // getName() -> inline constexpr in .h
}


