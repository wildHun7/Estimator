#ifndef SECTION_TYPE1_H
#define SECTION_TYPE1_H

#include "section.h"

namespace Sections
{

    class SectionType1 : public Section
    {
    public:
        explicit SectionType1(const std::string& name);

        void addItem(std::unique_ptr<Items::Item> item) override;

    };

}

#endif // SECTION_TYPE1_H
