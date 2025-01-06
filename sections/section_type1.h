#ifndef SECTION_TYPE1_H
#define SECTION_TYPE1_H

#include "section.h"

namespace Sections
{

    class SectionType1 : public Section
    {
    public:
        explicit SectionType1(const std::string& _name);

        void addItem(std::shared_ptr<Items::Item> _item) override;
    };

}

#endif // SECTION_TYPE1_H
