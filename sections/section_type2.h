#ifndef SECTION_TYPE2_H
#define SECTION_TYPE2_H

#include "section.h"

namespace Sections
{

    class SectionType2 : public Section
    {
    public:
        explicit SectionType2(const std::string& name);

<<<<<<< Updated upstream
        void addItem(std::unique_ptr<Items::Item> _item) override;
=======
        void addItem(std::unique_ptr<Items::Item> item) override;
>>>>>>> Stashed changes
    };

}

#endif // SECTION_TYPE2_H
