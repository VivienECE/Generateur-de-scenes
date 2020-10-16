///DETOURNAY-HILT-PICHON
#ifndef Soir_H
#define Soir_H

#include <Ciel.h>


class Soir : public Ciel
{
    public:
        Soir(double y1, double y2,std::mt19937& rg);

};

#endif // Soir_H
