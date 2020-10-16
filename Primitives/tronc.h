#ifndef TRONC_H
#define TRONC_H

#include <primitive.h>


class tronc : public Primitive
{
    public:
        tronc();
        virtual ~tronc();
        tronc(double x, double y, double coef);
        ///TRONC AU COORD x,y, COEF->]0;1]
        void dessiner(Svgfile& svgout) const;

    private:
        double m_x,m_y,m_coef;
};

#endif // TRONC_H
