#include "Etoilefilante.h"

Etoilefilante::Etoilefilante(Coords p1, Coords p2, std::mt19937& graine)
{
     std::vector <OptionGrad*> Liste;
    Liste.push_back(new OptionGrad(1,1,Svgfile::makeRGB(191,239,255)));
    Liste.push_back(new OptionGrad(100,0,Svgfile::makeRGB(256, 256, 256)));
    Gradient G("radial",50,50,40,0,50,Liste);
    double x=util::alea(p1.getX()+100,p2.getX()+100,graine);
    double y=util::alea(p1.getY(),p2.getY(),graine);
    ListePrimitives.push_back(new Ellipse_gradient(x,y,util::alea(50,150,graine),util::alea(1,3,graine), G));
    //std::cout << "++ voeu" << x <<  " - " << y <<std::endl;

}

Etoilefilante::~Etoilefilante()
{
    //dtor
}
