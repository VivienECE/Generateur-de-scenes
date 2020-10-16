///DETOURNAY-HILT-PICHON
#ifndef Etoile_H
#define Etoile_H

#include <objet.h>


class Etoile : public Objet
{
    public:
        Etoile(Coords p1, Coords p2, std::mt19937& graine);
        Etoile();
        virtual ~Etoile();


    protected:

    private:
};

#endif // Etoile_H
