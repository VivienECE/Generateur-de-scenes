#include "Jour.h"

Jour::Jour(double y1, double y2,std::mt19937& rg) : Ciel(y1,y2)
{
    std::string couleur;
    std::vector <OptionGrad*> ListeGradFond;
    double y_Soleil=util::alea(m_pos1.getY(),m_pos2.getY()/2,rg);
    double r=200;
    couleur=Svgfile::makeRGB(176,196,222);
    ListeGradFond.push_back(new OptionGrad(1,1,Svgfile::makeRGB(49, 140, 231)));
    ListeGradFond.push_back(new OptionGrad(100,1,Svgfile::makeRGB(49, 140, 231)));
    Gradient G("linear",0,100,0,0,ListeGradFond);
    ListeObjet.push_back(new Fond(m_pos1,m_pos2,G));

    int nbr_Objet=util::alea(10,20,rg);

    for(int i=0;i<nbr_Objet;i++)  //Nuage DEGRADE AVEC LE Fond
        ListeObjet.push_back(new Nuage(m_pos1,m_pos2,rg));

    std::vector <OptionGrad*> Liste; //AJOUTE GRADIENT SUR LES X NuageS
    Liste.push_back(new OptionGrad(30,1,Svgfile::makeRGB(176,196,222)));
    Liste.push_back(new OptionGrad(100,0,Svgfile::makeRGB(0, 127, 255))); //100 - BLANC
    Gradient H("linear",0,120,0,0,Liste);
    ListeObjet.push_back(new Fond(m_pos1,m_pos2,H));

    ListeObjet.push_back(new Soleil(m_pos1,m_pos2,rg,y_Soleil,r));

    for(int i=0;i<nbr_Objet;i++)  //Nuage BLANC
        ListeObjet.push_back(new Nuage(m_pos1,m_pos2,rg));
}

