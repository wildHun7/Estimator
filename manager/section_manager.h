#ifndef SECTION_MANAGER_H
#define SECTION_MANAGER_H

#include "section.h"

namespace Manager
{
    class SectionManager
    {
    public:
        SectionManager() = default;
        ~SectionManager() = default;

        const std::vector<std::unique_ptr<Sections::Section>>& getSections() const;

        // Managing sections
        void addSection(std::unique_ptr<Sections::Section> section);
        void removeSection(const std::string& name);
        int calculateTotalCosts() const;

        // Helper functions

        Sections::Section* findSection(const std::string& name);
        void addItemToSection(const std::string& name, std::unique_ptr<Items::Item> item);
        void removeItemFromSection(const std::string& sectionName, const std::string& itemName);

    private:
        std::vector<std::unique_ptr<Sections::Section>> m_section_list;
    };
}
#endif // SECTION_MANAGER_H
