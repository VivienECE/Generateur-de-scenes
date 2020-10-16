#include "tronc.h"

tronc::tronc()
{
    //ctor
}

tronc::~tronc()
{
    //dtor
}

tronc::tronc(double x, double y, double coef):m_x(x),m_y(y),m_coef(coef)
{

}

void tronc::dessiner(Svgfile& svgout) const
{
    svgout.addTronc(m_x,m_y,m_coef);
}
