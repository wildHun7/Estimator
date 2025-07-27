#include "section.h"

namespace Sections
{
    Section::Section(const std::string& name) : m_section_name(name)
    {
        // empty
    }

    const std::unordered_map<std::string, std::pair<std::unique_ptr<Items::Item>, int>>& Section::getItems() const
    {
        return this->m_section_items;
    }

    // Name

    const std::string& Section::getName() const
    {
        return m_section_name;
    }

    void Section::setName(const std::string& name)
    {
        this->m_section_name = name;
    }

    // Data

    void Section::removeItem(const std::string& name)
    {
        auto item = m_section_items.find(name);

        if(item != m_section_items.end())
            m_section_items.erase(item);
        else
            throw std::invalid_argument("Item not found: " + name);
    }

    void Section::updateItemCount(const std::string& name, int count)
    {
        auto item = m_section_items.find(name);

        if(item != m_section_items.end())
            item->second.second += count;
        else
            throw std::invalid_argument("Item not found");
    }

    int Section::calcTotal() const
    {
        if(m_section_items.empty())
            throw std::runtime_error("Section is empty");

        int total = 0;
        for(const auto& [name, pair] : m_section_items){
            total += pair.first->calcCosts() * pair.second;
        }
        return total;
    }
}

