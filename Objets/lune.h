///DETOURNAY-HILT-PICHON
#ifndef Lune_H
#define Lune_H

#include <objet.h>


class Lune : public Objet
{
    public:
        Lune(Coords p1, Coords p2, std::mt19937& graine);
        Lune();

        virtual ~Lune();

    protected:

    private:
};

#endif // Lune_H
