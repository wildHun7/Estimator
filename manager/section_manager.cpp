#include "section_manager.h"

namespace Manager
{
    const std::vector<std::unique_ptr<Sections::Section>>& SectionManager::getSections() const
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

    void SectionManager::removeSection(const std::string& name)
    {
        auto it = std::remove_if(m_section_list.begin(), m_section_list.end(), [&name]
                                 (const std::unique_ptr<Sections::Section>& section)
                                 {return section->getName() == name;} );

        if(it == m_section_list.end())
            throw std::runtime_error("Section not found: " + name);

        m_section_list.erase(it, m_section_list.end());
    }

    int SectionManager::calculateTotalCosts() const
    {
        int total = 0;
        for(const auto& section: m_section_list)
            total += section->calcTotal();

        return total;
    }

    /// Helper functions

    Sections::Section* SectionManager::findSection(const std::string& name)
    {
        for(const auto& section: m_section_list){
            if(section->getName() == name)
                return section.get();
        }
        throw std::runtime_error("Section not found: " + name);
    }

    void SectionManager::addItemToSection(const std::string& name, std::unique_ptr<Items::Item> item)
    {
        if(!item)
            throw std::invalid_argument("Null Item");

        auto section = findSection(name);
        section->addItem(std::move(item));
    }

    void SectionManager::removeItemFromSection(const std::string& sectionName, const std::string& itemName)
    {
        auto section = findSection(sectionName);
        section->removeItem(itemName);
    }
}


