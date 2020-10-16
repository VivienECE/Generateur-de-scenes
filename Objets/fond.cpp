#include "Fond.h"

Fond::Fond(Coords p1, Coords p2, std::string couleur)
{
    std::vector <Coords*> L;
    L.push_back(new Coords(p1.getX(),p1.getY()));
    L.push_back(new Coords(p1.getX(),p2.getY()));
    L.push_back(new Coords(p2.getX(),p2.getY()));
    L.push_back(new Coords(p2.getX(),p1.getY()));
    ListePrimitives.push_back(new Polygone(L,couleur));
}

Fond::Fond(std::vector <Coords*>& L, std::string couleur)
{
    ListePrimitives.push_back(new Polygone(L,couleur));
}

Fond::~Fond()
{
    //dtor
}

///Fond DEGRADE
Fond::Fond(Coords p1, Coords p2, Gradient G)
{
    std::vector <Coords*> L;
    L.push_back(new Coords(p1.getX(),p1.getY()));
    L.push_back(new Coords(p1.getX(),p2.getY()));
    L.push_back(new Coords(p2.getX(),p2.getY()));
    L.push_back(new Coords(p2.getX(),p1.getY()));
    ListePrimitives.push_back(new Polygone_gradient(L,G));
}
