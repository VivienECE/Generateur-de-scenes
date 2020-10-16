#include "Polygone_gradient.h"

Polygone_gradient::Polygone_gradient()
{
    //ctor
}

Polygone_gradient::~Polygone_gradient()
{
    //dtor
}

Polygone_gradient::Polygone_gradient(std::vector <Coords*>& Liste,Gradient G): Polygone(Liste,"blank"), m_gradient(G)
{

}

void Polygone_gradient::dessiner(Svgfile& svgout) const
{
    svgout.addPolygoneGradient(ListeSommet,m_gradient);
}
