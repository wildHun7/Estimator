#ifndef SECTION_H
#define SECTION_H

//#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "item.h"
#include "item_type1.h"
#include "item_type2.h"

namespace Sections
{
    class Section
    {
    public:
        explicit Section(std::string_view name);
        virtual ~Section() = default;

        // Items Getter unordered_map<string, pair<unique_ptr<Items::Item>, int>>
        constexpr const auto& getItems() const {return m_section_items;}

        // Name
        constexpr std::string_view getName() const noexcept {return m_section_name;}
        void setName(std::string_view name);

        // Managing Items
        virtual void addItem(std::unique_ptr<Items::Item> item, int quantity = 1) = 0;
        bool removeItem(std::string_view name);
        bool updateItemCount(std::string_view name, int count);

        std::optional<int> calcTotal() const noexcept;

    protected:
        std::string m_section_name;
        std::unordered_map<std::string, std::pair<std::unique_ptr<Items::Item>, int>> m_section_items;
    };
} //namespace Sections

#endif // SECTION_H
