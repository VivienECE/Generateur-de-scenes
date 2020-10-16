///DETOURNAY-HILT-PICHON
#ifndef Montagne_H
#define Montagne_H

#include <Objet.h>


class Montagne : public Objet
{
    public:
        Montagne(Coords p1, Coords p2, std::mt19937& graine);
        bool operator <(const Objet&G1);

    protected:

    private:
};



#endif // Montagne_H
