#include "section_manager.h"
//#include <numeric>
#include <algorithm>
#include <ranges>
#include <QMessageBox>

namespace Manager
{
    SectionManager::SectionManager(Database::DatabaseHandler* db) : m_db(db)
    {
        // intentionally empty
    }

    // getSections() -> inline constexpr in .h

    /// Managing sections

    void SectionManager::addSection(std::unique_ptr<Sections::Section> section)
    {
        if(!section)
            throw std::invalid_argument("null");

        m_section_list.push_back(std::move(section));
    }

    bool SectionManager::removeSection(std::string_view name)
    {
        return std::erase_if(m_section_list,
            [name](const auto& section)
            {
               return section->getName() == name;
            }
        ) > 0;
    }

    std::optional<int> SectionManager::calculateTotalCosts() const noexcept
    {
        if(m_section_list.empty())
            return std::nullopt;

        namespace rv = std::ranges::views;

        // Pipeline: sections → costs → sum
        auto costs = m_section_list
            | rv::transform([](const auto& section){
                return section->calcTotal();
            })
            | rv::filter([](const auto& opt){
                return opt.has_value();
            })
            | rv::transform([](const auto& opt){
                return *opt;
            });

        int total = 0;
        for(auto cost: costs)
        {
            total += cost;
        }

        return total;
    }

    /// Managing items

    Sections::Section* SectionManager::findSection(std::string_view section_name) const
    {
        auto item = std::ranges::find_if(m_section_list,
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

    // Database

    bool SectionManager::saveToDatabase()
    {
        if (!m_db) return false;

        if (!m_db->beginTransaction()) return false;

        if (!m_db->clearAllData()) {
            m_db->rollbackTransaction();
            return false;
        }

        bool success = std::ranges::all_of(m_section_list, [this](const auto& section){

            if (!m_db->saveSections(*section))
                return false;

            std::string section_name_str(section->getName());

            for (const auto& [item_name, item_pair] : section->getItems())
            {
                const auto& [item_ptr, quantity] = item_pair;

                if (!m_db->saveItem(
                        section_name_str,
                        item_name,
                        item_ptr->calcCosts(),
                        quantity))
                {
                    return false;
                }
            }
            return true;
        });

        if (success) {
            return m_db->commitTransaction();
        } else {
            m_db->rollbackTransaction();
            return false;
        }
    }

    bool SectionManager::loadFromDatabase()
    {
        if(!m_db)
            return false;

        auto loaded_sections = m_db->loadSections();

        if(loaded_sections.empty())
            return false;

        m_section_list = std::move(loaded_sections);

        return true;
    }
}


