///DETOURNAY-HILT-PICHON
#ifndef Triangle_H
#define Triangle_H

#include "Primitive.h"


class Triangle : public Primitive
{
    public:
        Triangle();
        Triangle(Coords pos1, Coords pos2, Coords pos3, std::string couleur);
        void dessiner(Svgfile& svgout) const;
        void homothetie(double coef);

    protected:
        Coords m_position1;
        Coords m_position2;
        Coords m_position3;

};

#endif // Triangle_H
