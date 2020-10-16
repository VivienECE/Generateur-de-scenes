#include "Lune.h"


Lune::Lune(Coords p1, Coords p2, std::mt19937& graine)
{
    std::vector <OptionGrad*> Liste; //Pleine Lune
    Liste.push_back(new OptionGrad(5,1,Svgfile::makeRGB(210,210,210)));
    Liste.push_back(new OptionGrad(5,1,Svgfile::makeRGB(200,200,200)));
    Liste.push_back(new OptionGrad(5,0,Svgfile::makeRGB(18, 1, 127)));
    Gradient G("radial",50,50,30,50,50,Liste);
    int x=util::alea(p1.getX(),p2.getX(),graine);
    int y=util::alea(p1.getY(),p2.getY(),graine);
    ListePrimitives.push_back(new Ellipse_gradient(x,y,300, G));//ctor

    std::vector <OptionGrad*> Liste1; //Cratères
    Liste1.push_back(new OptionGrad(80,1,Svgfile::makeRGB(180,180,180)));
    Liste1.push_back(new OptionGrad(80,1,Svgfile::makeRGB(180,180,180)));
    Liste1.push_back(new OptionGrad(100,0,Svgfile::makeRGB(180,180,180)));
    Gradient G1("radial",50,50,40,50,50,Liste1);
    int nbr_Objet=util::alea(5,10,graine);

    for(int i=0;i<nbr_Objet;i++)
        ListePrimitives.push_back(new Ellipse_gradient(x+util::alea(-5,5,graine),y+util::alea(-5,5,graine),util::alea(1,3,graine), G1));

    std::vector <OptionGrad*> Liste3;// Halo de lumière autour de la Lune
    Liste3.push_back(new OptionGrad(0,1,Svgfile::makeRGB(210,210,210)));
    Liste3.push_back(new OptionGrad(0,1,Svgfile::makeRGB(200,200,200)));
    Liste3.push_back(new OptionGrad(100,0,Svgfile::makeRGB(18, 1, 127)));
    Gradient G3("radial",50,50,30,50,50,Liste3);
    ListePrimitives.push_back(new Ellipse_gradient(x,y,100, G3));//ctor

    nbr_Objet=util::alea(5,10,graine);

    for(int i=0;i<nbr_Objet;i++)
    ListePrimitives.push_back(new Ellipse_gradient(x+util::alea(-5,5,graine),y+util::alea(-5,5,graine),util::alea(1,3,graine), G1));

   // std::cout << "++ Lune";
}

Lune::~Lune()
{
    //dtor
}
