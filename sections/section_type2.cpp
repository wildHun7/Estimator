#include "section_type2.h"

namespace Sections
{
    SectionType2::SectionType2(const std::string&_name) : Section(_name)
    {

    }

    void SectionType2::addItem(std::unique_ptr<Items::Item> _item)
    {
        if(dynamic_cast<Items::ItemType2*>(_item.get()))
        {
            for(const auto& [_itemPtr, _count]: m_sectionItems)
            {
                if(_itemPtr->getName() == _item->getName())
                    throw std::invalid_argument("Item with the same name already exist");
            }
            m_sectionItems.emplace(std::move(_item), 1);
        }
        else
            throw std::invalid_argument("Invalid item type for SectionType1");
    }
}
