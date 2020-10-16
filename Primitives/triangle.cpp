#include "Triangle.h"
#include "iostream"

Triangle::Triangle(): Primitive()
{

}

Triangle::Triangle(Coords pos1, Coords pos2, Coords pos3, std::string couleur): Primitive(couleur), m_position1{pos1}, m_position2{pos2},m_position3{pos3}
{

}

void Triangle::dessiner(Svgfile& svgout) const
{
    svgout.addTriangle(m_position1.getX(),m_position1.getY(),m_position2.getX(),m_position2.getY(),m_position3.getX(),m_position3.getY(), m_couleur);
}

void Triangle::homothetie(double coef)
{
    m_position1.addCoord((m_position1.getX()-m_position2.getX())*coef,0);
    m_position2.addCoord((m_position1.getX()-m_position2.getX())*coef,0);
    m_position3.addCoord((m_position1.getX()-m_position3.getX())*coef,(m_position1.getY()-m_position3.getY())*coef);
}
