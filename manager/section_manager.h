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

        const std::vector<std::unique_ptr<Sections::Section>>& getSections() const noexcept;

        // Managing sections
        void addSection(std::unique_ptr<Sections::Section> section);
        bool removeSection(std::string_view name);
        std::optional<int> calculateTotalCosts() const noexcept;

        // Helper functions

        Sections::Section* findSection(std::string_view name) const;
        bool addItemToSection(std::string_view section_name, std::unique_ptr<Items::Item> item);
        bool removeItemFromSection(std::string_view section_name, std::string_view item_name);

    private:
        std::vector<std::unique_ptr<Sections::Section>> m_section_list;
    };
}
#endif // SECTION_MANAGER_H
