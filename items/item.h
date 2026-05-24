#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <string_view>

namespace Items
{
    class Item
    {
    public:
        virtual ~Item() = default;

        // Name
        void setNameItem(std::string_view name);
        constexpr std::string_view getName() const noexcept {return m_item_name;};

        // Calculation
        virtual int calcCosts() const = 0;

    protected:
        Item() = default;
        explicit Item(std::string name) : m_item_name(std::move(name)) {}
        std::string m_item_name;
    };
}

#endif // ITEM_H
