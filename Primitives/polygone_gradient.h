///DETOURNAY-HILT-PICHON
#ifndef Polygone_GRADIENT_H
#define Polygone_GRADIENT_H

#include <Polygone.h>


class Polygone_gradient : public Polygone
{
    public:
        Polygone_gradient();
        virtual ~Polygone_gradient();
        Polygone_gradient(std::vector <Coords*>& Liste, Gradient G);
        void dessiner(Svgfile& svgout) const;
    protected:
        Gradient m_gradient;
};

#endif // Polygone_GRADIENT_H
