//#include <format>
#include "section_type1.h"

namespace Sections
{
    SectionType1::SectionType1(const std::string_view name) : Section(name)
    {
        // intentionally empty
    }

    void SectionType1::addItem(std::unique_ptr<Items::Item> item, int quantity)
    {
        auto* raw_ptr = item.get();
        if(!dynamic_cast<Items::Item*>(raw_ptr))
            throw std::invalid_argument("Invalid item type");
        if (quantity < 1)
            throw std::invalid_argument("Quantity must be positive");

        std::string item_name(raw_ptr->getName());

        auto [it, inserted] = m_section_items.try_emplace(
            std::move(item_name),  // key
            std::move(item),       // item unique ptr
            quantity
        );

        if(!inserted)
            throw std::invalid_argument("Item with the same name already exists"); // add std::format here!
    }
}
