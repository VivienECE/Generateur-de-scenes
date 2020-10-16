#include "Disk.h"
#include "iostream"

Disk::Disk()
{

}

Disk::Disk(Coords centre, double r, std::string couleur) : Primitive(couleur), m_centre{centre}, m_rayon{r}
{

}

void Disk::dessiner(Svgfile& svgout) const
{
    svgout.addDisk(m_centre.getX(),m_centre.getY(),m_rayon, m_couleur);
}

void homothetie(float coef)
{

}
