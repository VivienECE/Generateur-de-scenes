///DETOURNAY-HILT-PICHON
#ifndef EtoileFILANTE_H_INCLUDED
#define EtoileFILANTE_H_INCLUDED

#include <objet.h>


class Etoilefilante : public Objet
{
    public:
        Etoilefilante(Coords p1, Coords p2, std::mt19937& graine);

        Etoilefilante();
        virtual ~Etoilefilante();


    protected:

    private:
};


#endif // EtoileFILANTE_H_INCLUDED
