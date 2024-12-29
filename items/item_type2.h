#ifndef ITEM_TYPE2_H
#define ITEM_TYPE2_H

#include "item.h"

namespace Items {

    class ItemType2 : public Item
    {
    public:
        ItemType2(int _lCost, int _mCost);

        virtual int calcCosts() const override;

    private:
        int m_laborCost;
        int m_materialCost;
    };

}

#endif // ITEM_TYPE2_H
