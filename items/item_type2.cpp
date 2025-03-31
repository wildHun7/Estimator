#include "item_type2.h"

namespace Items {

    ItemType2::ItemType2(int lCost, int mCost) : m_laborCost(lCost), m_materialCost(mCost) {}

    int ItemType2::calcCosts() const
    {
        return m_laborCost + m_materialCost;
    }

}
