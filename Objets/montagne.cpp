///By Gauthier et Vivien
#include "Montagne.h"

Montagne::Montagne(Coords p1, Coords p2, std::mt19937& graine)
{
    do
    {
        double x,y,max_y=0;
        std::vector <Coords*> Liste; //Polygone
        std::vector <Coords*> ListeLigne; //Polyline relie sommet
        int r=util::alea(80,150,graine),g=util::alea(30,100,graine),b=util::alea(0,50,graine);
        std::string couleur=Svgfile::makeRGB(r,g,b); //COULEUR
        double v1,v2; //2 mode génération, Vers la droite ou vers la gauche du plan
        if((int)util::alea(0,1,graine)==0)
        {
            //Coords origine x,y
            x=0;
            y=p2.getY();
            v1=10;
            v2=20;
        }
        else
        {
            //x=p1.getX()+util::alea(400,800,graine); //Coords origine x,y
            x=p2.getX();
            y=p2.getY();
            v1=-10;
            v2=-20;
        }
        Liste.push_back(new Coords(x,y)); //BASE
        y-=util::alea(50,100,graine);//Hauteur du premier sommet d'une Montagne
        Liste.push_back(new Coords(x,y)); //1ier SOMMET

        for(int i=0;i<=p2.getX()/13;i++) //Rajoute plein de sommets au Polygone;
        {
            x+=util::alea(v1,v2,graine);
            y-=util::alea(-20,20,graine);
            if(y>p2.getY()) //SI SOMMET SOUS LA LIGNE DU PLAN, FIN Montagne
            {
                y=p2.getY();
                Liste.push_back(new Coords(x,y));
                ListeLigne.push_back(new Coords(x,y));
                break;
            }
            if(x<0) //SI SOMMET DEPASSE LA LIGNE DU PLAN GAUCHE, FIN Montagne
            {
                Liste.push_back(new Coords(0,y));
                ListeLigne.push_back(new Coords(0,y));
                Liste.push_back(new Coords(0,p2.getY()));
                ListeLigne.push_back(new Coords(0,p2.getY()));
                break;
            }
            if(y<p1.getY()) //SI SOMMET trop haut
            {
                y+=util::alea(1,20,graine);
            }
            Liste.push_back(new Coords(x,y));
            ListeLigne.push_back(new Coords(x,y));
            if(y>max_y)
                max_y=y;
        }
        if(y<p2.getY())
          Liste.push_back(new Coords(x,p2.getY())); //fermer la figure
        if(v2<0)
           Liste.push_back(new Coords(x,p2.getY()));

        ListePrimitives.push_back(new Polygone(Liste,couleur));
        ListePrimitives.push_back(new Polyline(Liste,"black",1)); //Ligne relie chaque sommet
        Coords pos(0,max_y); //Uniquement besoin de l'ordonnée pr le tri
        m_position=pos;

        //Ligne vers le bas, Ligne Relief
        int j=4; //Première ligne de Relief au 2nd sommet, voir boucle.
        //Couleur aléatoire du Relief, en fonction de la couleur de la Montagne
        r+=util::alea(-20,20,graine);
        g+=util::alea(-20,20,graine);
        b+=util::alea(-20,20,graine);
        couleur=Svgfile::makeRGB(r,g,b);

        for(const auto& i:Liste) //Parcours tout les sommets de la Montagne
        {
            j++; //Incremente +1 à chaque sommet parcouru
            ListeLigne.clear(); //Reset a chaque tour de boucle
            x=i->getX();
            y=i->getY();
            if((i-1)->getY()<i->getY()||(i+1)->getY()<i->getY()) //1 ligne de Relief tous les 6 sommets, si j multiple de 6->Ligne de Relief
            {

                ListeLigne.push_back(new Coords(x,y)); //sommet d'origine
                for(int k=0;k<=util::alea(4,15,graine);k++)//nbr point dans la ligne Relief
                {
                    x+=util::alea(-20,20,graine);//abscisse alea dns la descente
                    y+=util::alea(15,25,graine);//ordonnée alea dns la descente
                    if (y>p2.getY() || coords_in_polygon(x,y,Liste)==false)
                        break;
                    ListeLigne.push_back(new Coords(x,y));// Add un sommet
                }
                ListePrimitives.push_back(new Polyline(ListeLigne,"black",couleur,1)); //Dessine le Relief, relie tt les pts en noir et remplie par la couleur
            }
        }
        //std::cout << "++ Montagne";
        if (ListePrimitives.size()<15) //Assure des bel Montagnes si possible, et pas 1 ptit Triangle
            ListePrimitives.clear();

    }while (ListePrimitives.size()<15);

}


bool Montagne::operator <(const Objet&G1) //std::sort -> Affichera d'abord la Montagne avec le plus haut sommet...
{
    return (m_position.getY() < G1.getY());
}
