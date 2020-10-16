#include "ellipse_gradient_animated.h"
///OPTION ANIMATED MARCHE PAS SVGFILE
ellipse_gradient_animated::ellipse_gradient_animated()
{
    //ctor
}

ellipse_gradient_animated::~ellipse_gradient_animated()
{
    //dtor
}

ellipse_gradient_animated::ellipse_gradient_animated(double x,double y,double r,Gradient G): ellipse_gradient(x,y,r,G)
{

}

void ellipse_gradient_animated::dessiner(Svgfile& svgout) const
{
    svgout.addEllipseGradientAnimated(m_x,m_y,m_rx,m_ry,m_gradient);
}
