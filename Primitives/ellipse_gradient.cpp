#include "Ellipse_gradient.h"

Ellipse_gradient::Ellipse_gradient()
{
    //ctor
}

Ellipse_gradient::Ellipse_gradient(double x,double y,double rx,double ry, Gradient G):Ellipse(x,y,rx,ry,"black"), m_gradient(G)
{

}

Ellipse_gradient::Ellipse_gradient(double x,double y,double r,Gradient G):Ellipse(x,y,r,r,"black"), m_gradient(G)
{

}
void Ellipse_gradient::dessiner(Svgfile& svgout) const
{
    svgout.addEllipseGradient(m_x,m_y,m_rx,m_ry,m_gradient);
}
