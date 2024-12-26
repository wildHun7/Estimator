#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace Items {

    class Item
    {
    public:
        virtual ~Item() = default;

        // Name
        void setNameItem(std::string& _name);
        std::string getName();

        // Calculation
        virtual int calcCosts() const = 0;

    protected:
    std::string m_itemName;
    };

}

#endif // ITEM_H
