#ifndef SECTION_TYPE2_H
#define SECTION_TYPE2_H

#include "section.h"
#include <memory>
#include <string>

namespace Sections
{
    class SectionType2 : public Section
    {
    public:
        explicit SectionType2(const std::string& name);

        void addItem(std::unique_ptr<Items::Item> item, int quantity = 1) override;
    };
}

#endif // SECTION_TYPE2_H
