#include "section_type1.h"

namespace Sections
{
    SectionType1::SectionType1(const std::string& name) : Section(name)
    {

    }

<<<<<<< Updated upstream
    void SectionType1::addItem(std::unique_ptr<Items::Item> _item)
=======
    void SectionType1::addItem(std::unique_ptr<Items::Item> item)
>>>>>>> Stashed changes
    {
        if(dynamic_cast<Items::ItemType1*>(item.get()))
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
