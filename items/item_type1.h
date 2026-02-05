#ifndef ITEM_TYPE1_H
#define ITEM_TYPE1_H

#include "item.h"

namespace Items
{
    class ItemType1 : public Item
    {
    public:
        ItemType1(const std::string_view name, int lCost);

        int calcCosts() const override;

    private:
        int m_labor_cost;
    };
}

#endif // ITEM_TYPE1_H
