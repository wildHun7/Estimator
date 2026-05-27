#ifndef SECTION_MANAGER_H
#define SECTION_MANAGER_H

#include "section.h"
#include "database_handler.h"
#include <memory>
#include <optional>
#include <vector>
#include <string_view>

namespace Manager
{
    class SectionManager
    {
    public:
        explicit SectionManager(Database::DatabaseHandler* db = nullptr);
        ~SectionManager() = default;

        // vector<unique_ptr<Sections::Section>>
        constexpr const auto& getSections() const noexcept {return m_section_list;}

        // Managing sections
        void addSection(std::unique_ptr<Sections::Section> section);
        bool removeSection(std::string_view name);
        std::optional<int> calculateTotalCosts() const noexcept;

        // Managing items
        Sections::Section* findSection(std::string_view name) const;
        bool addItemToSection(std::string_view section_name, std::unique_ptr<Items::Item> item);
        bool removeItemFromSection(std::string_view section_name, std::string_view item_name);

        // Database
        bool saveToDatabase();
        bool loadFromDatabase();

    private:
        std::vector<std::unique_ptr<Sections::Section>> m_section_list;
        Database::DatabaseHandler* m_db;  // non-owning pointer
    };
}
#endif // SECTION_MANAGER_H
