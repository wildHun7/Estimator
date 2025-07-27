#include "section_type1.h"

namespace Sections
{
    SectionType1::SectionType1(const std::string& name) : Section(name)
    {

    }

    void SectionType1::addItem(std::unique_ptr<Items::Item> item)
    {
        if(dynamic_cast<Items::ItemType1*>(item.get()))
        {
            std::string item_name = item->getName();

            if(m_section_items.find(item_name) != m_section_items.end())
                throw std::invalid_argument("Item with the same name already exist");

            m_section_items.emplace(item_name, std::make_pair(std::move(item), 1));
        }
        else
            throw std::invalid_argument("Invalid item type for SectionType1");
    }
}
