#include "Polygone.h"
#include "iostream"

Polygone::~Polygone()
{

}

Polygone::Polygone(): Primitive()
{

}

Polygone::Polygone(std::vector <Coords*>& Liste,std::string couleur):Primitive(couleur), ListeSommet(Liste)
{

}

void Polygone::dessiner(Svgfile& svgout) const
{
    svgout.addPolygone(ListeSommet, m_couleur);
}
