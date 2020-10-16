///DETOURNAY-HILT-PICHON
#ifndef Polygone_H
#define Polygone_H

#include "Primitive.h"
#include <vector>

class Polygone : public Primitive
{
    public:
        Polygone();
        ~Polygone();
        Polygone(std::vector <Coords*>& Liste,std::string couleur);
        void dessiner(Svgfile& svgout) const;

    protected:
        std::vector <Coords*> ListeSommet;
};

#endif // Polygone_H
