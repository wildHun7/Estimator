#include "section_type2.h"

namespace Sections
{
    SectionType2::SectionType2(const std::string& name) : Section(name)
    {

    }

    void SectionType2::addItem(std::unique_ptr<Items::Item> item, int quantity)
    {
        if(dynamic_cast<Items::ItemType2*>(item.get()))
        {
            std::string item_name = item->getName();

            if(m_section_items.find(item_name) != m_section_items.end())
                throw std::invalid_argument("Item with the same name already exist");

            if (quantity < 1)
                throw std::invalid_argument("Quantity must be positive");

            m_section_items.emplace(item_name, std::make_pair(std::move(item), quantity));
        }
        else
            throw std::invalid_argument("Invalid item type for SectionType2");
    }
}
