#include "section_manager.h"
#include <numeric>

namespace Manager
{
    const std::vector<std::unique_ptr<Sections::Section>>& SectionManager::getSections() const noexcept
    {
        return m_section_list;
    }

    /// Managing sections

    void SectionManager::addSection(std::unique_ptr<Sections::Section> section)
    {
        if(!section)
            throw std::invalid_argument("null");

        m_section_list.push_back(std::move(section));
    }

    bool SectionManager::removeSection(std::string_view name)
    {
        auto it = std::remove_if(m_section_list.begin(), m_section_list.end(), [&name]
                                 (const std::unique_ptr<Sections::Section>& section)
                                 {return section->getName() == name;} );

        if(it == m_section_list.end())
            return false;

        m_section_list.erase(it, m_section_list.end());
        return true;
    }

    std::optional<int> SectionManager::calculateTotalCosts() const noexcept
    {
        if(m_section_list.empty())
            return std::nullopt;

        int total = std::accumulate(m_section_list.begin(), m_section_list.end(), 0,
                    [](int sum, const auto& section)
                    {
                        auto cost = section->calcTotal();
                        return sum + cost.value_or(0);
                    });

        return total;
    }

    /// Helper functions

    Sections::Section* SectionManager::findSection(std::string_view section_name) const
    {
        auto item = std::find_if(m_section_list.begin(), m_section_list.end(),
                    [section_name](const auto& section)
                    {
                        return section->getName() == section_name;
                    });

        if(item == m_section_list.end())
            return nullptr;

        return item->get();
    }

    bool SectionManager::addItemToSection(std::string_view section_name, std::unique_ptr<Items::Item> item)
    {
        if(!item)
            return false;

        auto* section = findSection(section_name);
        if(!section)
            return false;

        section->addItem(std::move(item));
        return true;
    }

    bool SectionManager::removeItemFromSection(std::string_view section_name, std::string_view item_name)
    {
        auto* section = findSection(section_name);
        if (!section)
            return false;

        return section->removeItem(item_name);
    }
}


