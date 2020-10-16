///DETOURNAY-HILT-PICHON
#ifndef Soleil_H
#define Soleil_H

#include <Objet.h>


class Soleil : public Objet
{
    public:
        Soleil(Coords p1, Coords p2, std::mt19937& graine, double y, double r);
        virtual ~Soleil();

    protected:

    private:
};

#endif // Soleil_H
