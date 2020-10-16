#include "Vague.h"

Vague::Vague(Coords p1, Coords p2, std::mt19937& graine)
{
    double x,y,max_y=0;
    std::vector <Coords*> Liste; //Polygone
    std::string couleur=Svgfile::makeRGB(util::alea(70,90,graine),util::alea(100,120,graine),util::alea(160,180,graine));
    int ymax=p2.getY()-p1.getY();
    x=p1.getX(); //Coords origine x,y
    y=p2.getY();

    Liste.push_back(new Coords(x,y));
    y-=util::alea(0,ymax,graine);//Hauteur du premier sommet d'une Vague
    Liste.push_back(new Coords(x,y));

    for(int i=0;i<=p2.getX()/40;i++) //Rajoute plein de sommets au Polygone;
    {
        x+=util::alea(35,45,graine);
        y-=util::alea(-3,3,graine);
        if(y<=p1.getY()) //Si depasse la partie haute du plan
            y+=3;
        Liste.push_back(new Coords(x,y));

       if(y>max_y) //std::sort
         max_y=y;
    }
    Liste.push_back(new Coords(p2.getX(),p2.getY())); //fermer la figure
    std::vector <OptionGrad*> ListeGrad;              //Applique Gradient
    ListeGrad.push_back(new OptionGrad(0,1,Svgfile::makeRGB(0, 127, 220)));
    ListeGrad.push_back(new OptionGrad(100,0,couleur));
    Gradient G("linear",0,100,0,0,ListeGrad);
    ListePrimitives.push_back(new Polygone_gradient(Liste,G));  //
    ListePrimitives.push_back(new Polyline(Liste,"white",0.1)); //Botte secrète pour vague parfaite

    Coords pos(0,max_y); //Uniquement besoin de l'ordonnée pr le tri
    m_position=pos;
}

bool Vague::operator <(const Objet&G1) //std::sort -> Affichera d'abord la Vague avec le plus haut sommet...
{
    return (m_position.getY() < G1.getY());
}
