///DETOURNAY-HILT-PICHON
///Finalement non utilisé dans les objets
#ifndef Line_H
#define Line_H

#include "Primitive.h"

class Line : public Primitive
{
    public:
        Line();
        Line(Coords pos1, Coords pos2, std::string couleur);
        void dessiner(Svgfile& svgout) const;

    protected:
        Coords m_position1;
        Coords m_position2;

};

#endif // Line_H
