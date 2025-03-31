#include "item_type1.h"

namespace Items {

    ItemType1::ItemType1(int lCost) : m_laborCost(lCost) {}

    int ItemType1::calcCosts() const
    {
        return m_laborCost;
    }

}
