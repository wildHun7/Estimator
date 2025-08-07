#ifndef ITEM_TYPE2_H
#define ITEM_TYPE2_H

#include "item.h"

namespace Items
{
    class ItemType2 : public Item
    {
    public:
        ItemType2(int lCost, int mCost);

        virtual int calcCosts() const override;

    private:
        int m_labor_cost;
        int m_material_cost;
    };
}

#endif // ITEM_TYPE2_H
