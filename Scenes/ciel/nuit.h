///DETOURNAY-HILT-PICHON
#ifndef Nuit_H
#define Nuit_H

#include <Ciel.h>

class Nuit : public Ciel
{
    public:
        Nuit(double y1, double y2,std::mt19937& rg);
};

#endif // Nuit_H
