#ifndef SECTIONTYPE2_H
#define SECTIONTYPE2_H

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

#endif // SECTIONTYPE2_H
