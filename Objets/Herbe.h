///DETOURNAY-HILT-PICHON
#ifndef Herbe_H
#define Herbe_H

#include <Objet.h>


class Herbe : public Objet
{
    public:
        Herbe();
        Herbe(Coords p1, Coords p2, std::mt19937& graine);
        Herbe(std::vector <Coords*>& Liste, std::mt19937& graine);
        bool operator <(const Objet&G1);
};

#endif // Herbe_H
