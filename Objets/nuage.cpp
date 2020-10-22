#include "Nuage.h"

Nuage::Nuage(Coords p1, Coords p2, std::mt19937& graine)
{
    float coef;
    std::vector <OptionGrad*> Liste;
    int a=220;
    int b=230;
    Liste.push_back(new OptionGrad(5,1,Svgfile::makeRGB(a,a,a)));
    Liste.push_back(new OptionGrad(30,1,Svgfile::makeRGB(b,b,b)));
    Liste.push_back(new OptionGrad(100,0,Svgfile::makeRGB(250,250,200)));
    int x=util::alea(-20,(int)p2.getX(),graine);
    int y=util::alea(-30,(int)p2.getY(),graine);
    Gradient G("radial",40,40,40,60,60,Liste);
    int nbr_Objet=util::alea(20,35,graine);
    for(int i=0;i<nbr_Objet;i++)
    {
        x+=util::alea(-10,20,graine);
        y+=util::alea(-15,10,graine);
        coef=1-y/p2.getY();  //Homothetie direct
        ListePrimitives.push_back(new Ellipse_gradient(x,y,util::alea(80,130,graine)*coef,util::alea(40,60,graine)*coef, G));
       // ListePrimitives.push_back(new Ellipse_gradient(x+util::alea(-40,40,graine),y+util::alea(-25,25,graine),util::alea(50,130,graine)*coef, //GAUTHIER
                                                   //    util::alea(40,60,graine)*coef, G));
    }
}
