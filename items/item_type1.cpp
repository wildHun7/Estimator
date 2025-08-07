#include "item_type1.h"

namespace Items
{
    ItemType1::ItemType1(const std::string& name, int l_cost) : m_labor_cost(l_cost)
    {
        m_item_name = name;
    }

    int ItemType1::calcCosts() const
    {
        return m_labor_cost;
    }
}
