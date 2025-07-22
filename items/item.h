#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace Items {

    class Item
    {
    public:
        virtual ~Item() = default;

        // Name
        void setNameItem(std::string& name);
        std::string getName() const;

        // Calculation
        virtual int calcCosts() const = 0;

    protected:
    std::string m_item_name;
    };

}

#endif // ITEM_H
