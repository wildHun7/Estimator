#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

#include "item.h"
#include "item_type1.h"
#include "item_type2.h"

namespace Sections
{

    class Section
    {
    public:
        explicit Section(const std::string& name);
        virtual ~Section() = default;

        // Items Getter
        const std::unordered_map<std::unique_ptr<Items::Item>, int>& getItems() const;

        // Name
        const std::string& getName() const; // 2nd const preventing from modification of the object
        void setName(const std::string& name);

        // Managing Items
        virtual void addItem(std::unique_ptr<Items::Item> item) = 0;
        void removeItem(const std::string& name);
        void updateItemCount(const std::string& name, int count);

        virtual int calcTotal() const;

    protected:
        std::string m_sectionName;
        std::unordered_map<std::unique_ptr<Items::Item>, int> m_sectionItems;
    };

} //namespace Sections

#endif // SECTION_H
