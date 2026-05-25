#ifndef SECTION_TYPE1_H
#define SECTION_TYPE1_H

#include "section.h"
#include <memory>
#include <string_view>

namespace Sections
{
    class SectionType1 : public Section
    {
    public:
        explicit SectionType1(std::string_view name);

        void addItem(std::unique_ptr<Items::Item> item, int quantity = 1) override;
    };
}

#endif // SECTION_TYPE1_H
