#include "section_type2.h"

namespace Sections
{
    SectionType2::SectionType2(const std::string& name) : Section(name)
    {

    }

    void SectionType2::addItem(std::unique_ptr<Items::Item> item)
    {
        if(dynamic_cast<Items::ItemType2*>(item.get()))
        {
            for(const auto& [itemPtr, count]: m_sectionItems)
            {
                if(itemPtr->getName() == item->getName())
                    throw std::invalid_argument("Item with the same name already exist");
            }
            m_sectionItems.emplace(std::move(item), 1);
        }
        else
            throw std::invalid_argument("Invalid item type for SectionType1");
    }
}
