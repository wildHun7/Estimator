#include "section.h"

namespace Sections
{
    Section::Section(const std::string& _name) : m_sectionName(_name)
    {
        // empty
    }

    const std::string& Section::getName() const
    {
        return m_sectionName;
    }

    void Section::setName(const std::string& _name)
    {
        this->m_sectionName = _name;
    }

    void Section::removeItem(const std::string& _name)
    {
        auto it = std::find_if(m_sectionItems.begin(), m_sectionItems.end(),
                               [&_name](const auto& _mp){ return _mp.first->getName() == _name;
                               });

        if(it != m_sectionItems.end())
            m_sectionItems.erase(it);
        else
            throw std::invalid_argument("Item not found: " + _name);
    }

    void Section::updateItemCount(const std::string& _name, int _count)
    {
        for(auto it = m_sectionItems.begin(); it != m_sectionItems.end(); ++it)
        {
            if(it->first->getName() == _name)
            {
                it->second += _count;
                return;
            }
        }

        throw std::invalid_argument("Item not found");
    }

    int Section::calcTotal() const
    {
        if(m_sectionItems.empty())
            throw std::runtime_error("Section is empty");

        int total = 0;
        for(const auto& [_itemPtr, _count] : m_sectionItems){
            total += _itemPtr->calcCosts() * _count;
        }
        return total;
    }
}

