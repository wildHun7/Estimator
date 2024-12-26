#ifndef ITEMTYPE1_H
#define ITEMTYPE1_H

#include "item.h"

namespace Items {

    class ItemType1 : public Item
    {
    public:
        ItemType1(int _lCost);

        virtual int calcCosts() const override;

    private:
        int m_laborCost;
    };

}

#endif // ITEMTYPE1_H
