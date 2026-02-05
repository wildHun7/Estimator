#include "section.h"

namespace Sections
{
    Section::Section(const std::string_view name) : m_section_name(name)
    {
        // empty
    }

    const std::unordered_map<std::string, std::pair<std::unique_ptr<Items::Item>, int>>& Section::getItems() const
    {
        return m_section_items;
    }

    // Name

    std::string_view Section::getName() const noexcept
    {
        return m_section_name;
    }

    void Section::setName(const std::string_view name)
    {
        m_section_name = name;
    }

    // Data

    bool Section::removeItem(const std::string_view name)
    {
        auto item = m_section_items.find(std::string(name));

        if(item != m_section_items.end())
        {
            m_section_items.erase(item);
            return true;
        }
        return false;
    }

    bool Section::updateItemCount(const std::string_view name, int count)
    {
        auto item = m_section_items.find(std::string(name));

        if(item != m_section_items.end())
        {
            item->second.second += count;
            return true;
        }
        return false;
    }

    std::optional<int> Section::calcTotal() const noexcept
    {
        if(m_section_items.empty())
            return std::nullopt;

        int total = 0;
        for(const auto& [name, item_pair] : m_section_items)
        {
            const auto& [item_ptr, quantity] = item_pair;
            total += item_ptr->calcCosts() * quantity;
        }
        return total;
    }
}

