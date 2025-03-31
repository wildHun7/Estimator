#ifndef SECTION_TYPE1_H
#define SECTION_TYPE1_H

#include "section.h"

namespace Sections
{

    class SectionType1 : public Section
    {
    public:
        explicit SectionType1(const std::string& name);

<<<<<<< Updated upstream
        void addItem(std::unique_ptr<Items::Item> _item) override;
=======
        void addItem(std::unique_ptr<Items::Item> item) override;
>>>>>>> Stashed changes
    };

}

#endif // SECTION_TYPE1_H
