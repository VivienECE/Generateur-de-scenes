#include "Soleil.h"

Soleil::~Soleil()
{
    //dtor
}

Soleil::Soleil(Coords p1, Coords p2, std::mt19937& graine, double y, double r)
{
    std::vector <OptionGrad*> Liste;
    Liste.push_back(new OptionGrad(1,1,Svgfile::makeRGB(256,256,256)));
    Liste.push_back(new OptionGrad(10,1,Svgfile::makeRGB(256,256,5)));
    Liste.push_back(new OptionGrad(100,0,Svgfile::makeRGB(256,256,256)));
    Gradient G("radial",50,50,50,50,50,Liste);
    ListePrimitives.push_back(new Ellipse_gradient(util::alea(p1.getX(),p2.getX(),graine),y, r , G));
}
