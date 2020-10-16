#include "Polyline.h"

Polyline::~Polyline()
{

}

Polyline::Polyline(): Primitive()
{

}

Polyline::Polyline(std::vector <Coords*>& Liste,std::string couleur, double ep):Primitive(couleur), ListeSommet(Liste), m_ep(ep)
{

}

Polyline::Polyline(std::vector <Coords*>& Liste,std::string couleur, std::string couleur2, double ep):Primitive(couleur), ListeSommet(Liste), m_ep(ep), m_couleur2(couleur2)
{

}

void Polyline::dessiner(Svgfile& svgout) const
{
    if(m_couleur2=="blank")
        svgout.addPolyline(ListeSommet, m_couleur, m_ep);
    else
        svgout.addPolyline(ListeSommet, m_couleur, m_couleur2, m_ep);
}



