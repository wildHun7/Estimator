#include "section_manager.h"

namespace Manager
{
    const std::vector<std::unique_ptr<Sections::Section>>& SectionManager::getSections() const
    {
        return m_sectionList;
    }

    /// Managing sections

    void SectionManager::addSection(std::unique_ptr<Sections::Section> section)
    {
        if(!section)
            throw std::invalid_argument("null");

        m_sectionList.push_back(std::move(section));
    }

    void SectionManager::remvSection(const std::string& name)
    {
        auto it = std::remove_if(m_sectionList.begin(), m_sectionList.end(), [&name]
                                 (const std::unique_ptr<Sections::Section>& section)
                                 {return section->getName() == name;} );

        if(it == m_sectionList.end())
            throw std::runtime_error("Section not found: " + name);

        m_sectionList.erase(it, m_sectionList.end());
    }

    int SectionManager::calculateTotalCosts() const
    {
        int total = 0;
        for(const auto& section: m_sectionList)
            total += section->calcTotal();

        return total;
    }

    /// Helper functions

    Sections::Section* SectionManager::findSection(const std::string& name)
    {
        for(const auto& section: m_sectionList){
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


