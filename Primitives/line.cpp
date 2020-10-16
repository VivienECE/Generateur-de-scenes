#include "Line.h"
#include "iostream"
Line::Line(): Primitive()
{

}

Line::Line(Coords pos1, Coords pos2, std::string couleur): Primitive(couleur), m_position1{pos1}, m_position2{pos2}
{

}

void Line::dessiner(Svgfile& svgout) const
{
    svgout.addLine(m_position1.getX(),m_position1.getY(),m_position2.getX(),m_position2.getY(), m_couleur);
}

