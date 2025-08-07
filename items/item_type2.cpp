#include "item_type2.h"

namespace Items
{
    ItemType2::ItemType2(int l_cost, int m_cost) : m_labor_cost(l_cost), m_material_cost(m_cost) {}

    int ItemType2::calcCosts() const
    {
        return m_labor_cost + m_material_cost;
    }
}
