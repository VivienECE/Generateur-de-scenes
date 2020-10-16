#include "Ellipse.h"
#include "iostream"

Ellipse::~Ellipse()
{

}

Ellipse::Ellipse()
{

}

Ellipse::Ellipse(double x,double y,double rx,double ry,std::string couleur):Primitive(couleur), m_x(x),m_y(y),m_rx(rx),m_ry(ry)
{

}

void Ellipse::dessiner(Svgfile& svgout) const
{
        svgout.addEllipse(m_x,m_y,m_rx,m_ry,m_couleur);
}

