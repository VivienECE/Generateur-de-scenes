///DETOURNAY-HILT-PICHON
#ifndef Ellipse_H
#define Ellipse_H

#include <Primitive.h>


class Ellipse : public Primitive
{
    public:
        virtual ~Ellipse();
        Ellipse();
        Ellipse(double x,double y,double rx,double ry,std::string couleur);
        virtual void dessiner(Svgfile& svgout) const;

    protected:
        double m_x,m_y,m_rx,m_ry;
};

#endif // Ellipse_H
