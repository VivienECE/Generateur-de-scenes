///DETOURNAY-HILT-PICHON
#ifndef Ellipse_GRADIENT_H
#define Ellipse_GRADIENT_H

#include <Ellipse.h>

class Ellipse_gradient : public Ellipse
{
    public:
        Ellipse_gradient();
        Ellipse_gradient(double x,double y,double rx,double ry,Gradient G);
        Ellipse_gradient(double x,double y,double r,Gradient G);
        void dessiner(Svgfile& svgout) const;

    protected:
        Gradient m_gradient;
};

#endif // Ellipse_GRADIENT_H
