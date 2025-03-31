#include "section.h"

namespace Sections
{
    Section::Section(const std::string& name) : m_sectionName(name)
    {
        // empty
    }

<<<<<<< Updated upstream
=======
    const std::unordered_map<std::unique_ptr<Items::Item>, int>& Section::getItems() const
    {
        return this->m_sectionItems;
    }

    // Name

>>>>>>> Stashed changes
    const std::string& Section::getName() const
    {
        return m_sectionName;
    }

    void Section::setName(const std::string& name)
    {
        this->m_sectionName = name;
    }

<<<<<<< Updated upstream
    void Section::removeItem(const std::string& _name)
=======
    // Data

    void Section::removeItem(const std::string& name)
>>>>>>> Stashed changes
    {
        auto it = std::find_if(m_sectionItems.begin(), m_sectionItems.end(),
                               [&name](const auto& mp){ return mp.first->getName() == name;
                               });

        if(it != m_sectionItems.end())
            m_sectionItems.erase(it);
        else
            throw std::invalid_argument("Item not found: " + name);
    }

    void Section::updateItemCount(const std::string& name, int count)
    {
        for(auto it = m_sectionItems.begin(); it != m_sectionItems.end(); ++it)
        {
            if(it->first->getName() == name)
            {
                it->second += count;
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
        for(const auto& [itemPtr, count] : m_sectionItems){
            total += itemPtr->calcCosts() * count;
        }
        return total;
    }
}

