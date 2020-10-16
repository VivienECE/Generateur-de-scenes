#include "Nuit.h"

Nuit::Nuit(double y1, double y2,std::mt19937& rg) : Ciel(y1,y2)
{
    //std::cout << "Nuit";
    std::vector <OptionGrad*> ListeGradFond;
    ListeGradFond.push_back(new OptionGrad(1,1,Svgfile::makeRGB(75, 40, 187)));//BAS
    ListeGradFond.push_back(new OptionGrad(100,1,Svgfile::makeRGB(0,0,0)));//HAUT
    Gradient G("linear",0,100,0,0,ListeGradFond);

    ListeObjet.push_back(new Fond(m_pos1,m_pos2,G));
    int nbr_Objet=util::alea(250,1000,rg);


    for(int i=0;i<nbr_Objet;i++)
       ListeObjet.push_back(new Etoile(m_pos1,m_pos2,rg));

    nbr_Objet=util::alea(1,1,rg);

    for(int i=0;i<nbr_Objet;i++)
        ListeObjet.push_back(new Etoilefilante(m_pos1,m_pos2,rg));

    ListeObjet.push_back(new Lune(m_pos1,m_pos2,rg));

}

