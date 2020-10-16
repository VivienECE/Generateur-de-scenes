#include "Etoile.h"

Etoile::Etoile(Coords p1, Coords p2, std::mt19937& graine)
{
    std::vector <OptionGrad*> Liste;
    Liste.push_back(new OptionGrad(1,1,Svgfile::makeRGB(191,239,255)));
    Liste.push_back(new OptionGrad(100,0,Svgfile::makeRGB(18, 1, 127)));
    Gradient G("radial",50,50,10,50,50,Liste);
    ListePrimitives.push_back(new Ellipse_gradient(util::alea(p1.getX(),p2.getX(),graine),util::alea(p1.getY(),p2.getY(),graine),util::alea(2,25,graine), G));
}

Etoile::~Etoile()
{
    //dtor
}
