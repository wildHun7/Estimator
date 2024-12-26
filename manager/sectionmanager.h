#ifndef SECTIONMANAGER_H
#define SECTIONMANAGER_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "section.h"

namespace Manager
{
    class SectionManager
    {
    public:
        SectionManager() = default;
        ~SectionManager() = default;

        // Managing sections
        void addSection(std::unique_ptr<Sections::Section> _section);
        void remvSection(const std::string& _name);
        int calculateTotalCosts() const;

        // Helper functions
        Sections::Section* findSection(const std::string& _name);
        void addItemToSection(const std::string& _name, std::unique_ptr<Items::Item> _item);
        void removeItemFromSection(const std::string& _sectionName, const std::string& _itemName);

    private:
        std::vector<std::unique_ptr<Sections::Section>> m_sectionList;
    };
}
#endif // SECTIONMANAGER_H
