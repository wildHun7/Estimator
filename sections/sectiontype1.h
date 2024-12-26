#ifndef SECTIONTYPE1_H
#define SECTIONTYPE1_H

#include "section.h"

namespace Sections
{
    class SectionType1 : public Section
    {
    public:
        explicit SectionType1(const std::string& _name);

        void addItem(std::unique_ptr<Items::Item> _item) override;
    };
}

#endif // SECTIONTYPE1_H
