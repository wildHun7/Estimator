#include "section_manager.h"

namespace Manager
{
    const std::vector<std::unique_ptr<Sections::Section>>& SectionManager::getSections() const
    {
        return m_sectionList;
    }

    /// Managing sections

    void SectionManager::addSection(std::unique_ptr<Sections::Section> _section)
    {
        if(!_section)
            throw std::invalid_argument("null");

        m_sectionList.push_back(std::move(_section));
    }

    void SectionManager::remvSection(const std::string& _name)
    {
        auto it = std::remove_if(m_sectionList.begin(), m_sectionList.end(), [&_name]
                                 (const std::unique_ptr<Sections::Section>& _section)
                                 {return _section->getName() == _name;} );

        if(it == m_sectionList.end())
            throw std::runtime_error("Section not found: " + _name);

        m_sectionList.erase(it, m_sectionList.end());
    }

    int SectionManager::calculateTotalCosts() const
    {
        int total = 0;
        for(const auto& _section: m_sectionList)
            total += _section->calcTotal();

        return total;
    }

    /// Helper functions

    Sections::Section* SectionManager::findSection(const std::string& _name)
    {
        for(const auto& _section: m_sectionList){
            if(_section->getName() == _name)
                return _section.get();
        }
        throw std::runtime_error("Section not found: " + _name);
    }

    void SectionManager::addItemToSection(const std::string& _name, std::shared_ptr<Items::Item> _item)
    {
        if(!_item)
            throw std::invalid_argument("Null Item");

        auto _section = findSection(_name);
        _section->addItem(std::move(_item));
    }

    void SectionManager::removeItemFromSection(const std::string& _sectionName, const std::string& _itemName)
    {
        auto _section = findSection(_sectionName);
        _section->removeItem(_itemName);
    }
}


