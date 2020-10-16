#include "Herbe.h"
#include "iostream"

Herbe::Herbe()
{
    //ctor
}
Herbe::Herbe(Coords p1, Coords p2, std::mt19937& graine)
{
    double x1,y1,x2,y2,x3,y3;
    Coords pos1,pos2,pos3;
    //1 Triangle incliné vert
    x1=util::alea(p1.getX(),p2.getX(),graine); //Coords origine x,y
    y1=util::alea(p1.getY(),p2.getY(),graine);


    x2=x1+util::alea(2,4,graine);//Base
    y2=y1;
    y3=y1-util::alea(25,40,graine);//Hauteur
    x3=x1+util::alea(-10,12,graine);//Orientation pointe
    pos1.setCoord(x1,y1);
    m_position=pos1;
    pos2.setCoord(x2,y2);
    pos3.setCoord(x3,y3);
    ListePrimitives.push_back(new Triangle{pos1,pos2,pos3,Svgfile::makeRGB(util::alea(0,50,graine),util::alea(50,256,graine),util::alea(0,50,graine))});
}

Herbe::Herbe(std::vector <Coords*>& Liste, std::mt19937& graine)
{
    double x1,y1,x2,y2,x3,y3;
    Coords pos1,pos2,pos3;
    double xmin,xmax,ymin,ymax;
    xmax=Liste[0]->getX();
    ymax=Liste[0]->getY();
    ymin=ymax;
    xmin=xmax;
    for(const auto& i:Liste)
    {
        if(xmax>i->getX())
            xmax=i->getX();
        if(xmin<i->getX())
            xmin=i->getX();
        if(ymax>i->getY())
            ymax=i->getY();
        if(ymin<i->getY())
            ymin=i->getY();
    }
    //1 Triangle incliné vert
    do
    {
        x1=util::alea(xmin,xmax,graine);
        y1=util::alea(ymin,ymax,graine);
    }while(coords_in_polygon(x1,y1,Liste)==false); //Definit dans objet.cpp

    x2=x1+util::alea(2,4,graine);//Base
    y2=y1;
    y3=y1-util::alea(25,40,graine);//Hauteur
    x3=x1+util::alea(-10,12,graine);//Orientation pointe
    pos1.setCoord(x1,y1);
    m_position=pos1;
    pos2.setCoord(x2,y2);
    pos3.setCoord(x3,y3);
    ListePrimitives.push_back(new Triangle{pos1,pos2,pos3,Svgfile::makeRGB(util::alea(0,50,graine),util::alea(50,256,graine),util::alea(0,50,graine))});
}

bool Herbe::operator <(const Objet&G1)
{
    return (m_position.getY() < G1.getY());
}


