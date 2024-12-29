#include "item_type1.h"

namespace Items {

    ItemType1::ItemType1(int _lCost) : m_laborCost(_lCost) {}

    int ItemType1::calcCosts() const
    {
        return m_laborCost;
    }

}
