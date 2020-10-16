#include "Ciel.h"

Ciel::Ciel(double x, double y) : Plan(x,y)
{
    Coords pos_Fond(800,800);
    ListeObjet.push_back(new Fond(m_pos1,pos_Fond,Svgfile::makeRGB(25,25,150)));
}

/***
PLUS Soleil BAS, PLUS Fond -> Soir
PLUS Soleil HAUT, PLUS Fond -> JOURNEE

Fond Nuit:
25,25,112

Fond Soir:
253,94,83

Fond Jour:
176,196,222
**/
