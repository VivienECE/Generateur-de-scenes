///DETOURNAY-HILT-PICHON
#ifndef Nuage_H
#define Nuage_H

#include <Objet.h>


class Nuage : public Objet
{
    public:
        Nuage(Coords p1, Coords p2, std::mt19937& graine);

    private:
};

#endif // Nuage_H
