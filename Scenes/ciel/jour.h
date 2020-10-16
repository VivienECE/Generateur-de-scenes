///DETOURNAY-HILT-PICHON
#ifndef Jour_H
#define Jour_H

#include <Ciel.h>


class Jour : public Ciel
{
    public:
        Jour(double y1, double y2,std::mt19937& rg);
};

#endif // Jour_H
