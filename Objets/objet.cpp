#include "Objet.h"
#include <fstream>

Objet::Objet()
{
}

Objet::Objet(Coords pos1, Coords pos2)
{

}

Objet::~Objet()
{
}

void Objet::dessiner(Svgfile& svgout) const
{
    for(const auto& i:ListePrimitives)
        i->dessiner(svgout);
}

double Objet::getY() const
{
    return m_position.getY();
}

double Objet::getX() const
{
    return m_position.getX();
}

bool Objet::operator <(const Objet&G1)
{
    return this->m_position.getY() < G1.m_position.getY();
}

void Objet::homothetie(float coef)
{
    for(const auto& i:ListePrimitives)
      i->homothetie(coef);
}

bool coords_in_polygon(double x, double y, std::vector <Coords*>& Liste)
{
    int i,j, nvert = Liste.size();
    bool c = false;

    for(i = 0, j = nvert - 1; i < nvert; j = i++)
    {
        if( ( (Liste[i]->getY() >= y ) != (Liste[j]->getY() >= y) ) &&
            (x <= (Liste[j]->getX() - Liste[i]->getX()) * (y - Liste[i]->getY()) / (Liste[j]->getY() - Liste[i]->getY()) + Liste[i]->getX())
          )
      c = !c;
    }
    return c;
}
