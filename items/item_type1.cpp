#include "item_type1.h"

namespace Items
{
    ItemType1::ItemType1(const std::string_view name, int l_cost)
        : Item(std::string(name))
        , m_labor_cost(l_cost)
    {
        // intentionally empty
    }

    int ItemType1::calcCosts() const
    {
        return m_labor_cost;
    }
}
