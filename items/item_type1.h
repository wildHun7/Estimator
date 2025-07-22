#ifndef ITEM_TYPE1_H
#define ITEM_TYPE1_H

#include "item.h"

namespace Items {

    class ItemType1 : public Item
    {
    public:
        ItemType1(int lCost);

        virtual int calcCosts() const override;

    private:
        int m_labor_cost;
    };

}

#endif // ITEM_TYPE1_H
