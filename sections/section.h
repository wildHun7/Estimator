#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

#include "item.h"
#include "itemtype1.h"
#include "itemtype2.h"

namespace Sections
{
    class Section
    {
    public:
        explicit Section(const std::string& _name);
        virtual ~Section() = default;

        // Name
        const std::string& getName() const; // 2nd const preventing from modification of the object
        void setName(const std::string& _name);

        // Data
        virtual void addItem(std::unique_ptr<Items::Item> _item) = 0;
        void removeItem(const std::string& _name);
        void updateItemCount(const std::string& _name, int _count);
        virtual int calcTotal() const;

    protected:
        std::string m_sectionName;
        std::unordered_map<std::unique_ptr<Items::Item>, int> m_sectionItems;
    };
} //namespace Sections

#endif // SECTION_H
