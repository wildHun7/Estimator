#include "item_type1.h"

namespace Items {

    ItemType1::ItemType1(int l_cost) : m_labor_cost(l_cost) {}

    int ItemType1::calcCosts() const
    {
        return m_labor_cost;
    }

}
