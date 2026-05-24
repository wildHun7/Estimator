#include "section.h"

namespace Sections
{
    Section::Section(const std::string_view name) : m_section_name(name)
    {
        // empty
    }

    // getItems() -> inline constexpr in .h

    // Name

    // getName() -> inline constexpr in .h

    void Section::setName(const std::string_view name)
    {
        m_section_name = name;
    }

    // Managing Items

    bool Section::removeItem(const std::string_view name)
    {
        return std::erase_if(m_section_items,
                [name](const auto& pair){
                    return pair.first == name;
                }) > 0;
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

        namespace rv = std::ranges::views;

        auto costs = m_section_items
            | rv::values // pairs<ptr, qty>
            | rv::transform([](const auto& item_pair){
                const auto& [item_ptr, qty] = item_pair;
                return item_ptr->calcCosts() * qty;
            });

        int total = 0;
        for(auto cost: costs)
        {
            total += cost;
        }
        return total;
    }
}

