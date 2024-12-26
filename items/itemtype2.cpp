#include "itemtype2.h"

namespace Items {

    ItemType2::ItemType2(int _lCost, int _mCost) : m_laborCost(_lCost), m_materialCost(_mCost) {}

    int ItemType2::calcCosts() const
    {
        return m_laborCost + m_materialCost;
    }

}
