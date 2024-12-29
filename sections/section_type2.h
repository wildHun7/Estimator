#ifndef SECTION_TYPE2_H
#define SECTION_TYPE2_H

#include "section.h"

namespace Sections
{

    class SectionType2 : public Section
    {
    public:
        explicit SectionType2(const std::string& _name);

        void addItem(std::unique_ptr<Items::Item> _item) override;
    };

}

#endif // SECTION_TYPE2_H
