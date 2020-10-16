#include "Soir.h"

Soir::Soir(double y1, double y2,std::mt19937& rg) : Ciel(y1,y2)
{
    std::string couleur;
    std::vector <OptionGrad*> ListeGradFond;

    double y_Soleil=util::alea(m_pos2.getY()/2,m_pos2.getY(),rg);
    double r=500;

    //std::cout << "Soir";
    couleur=Svgfile::makeRGB(253,94,83);//Conserve qd même, reutilisé ensuite
    ListeGradFond.push_back(new OptionGrad(30,1,Svgfile::makeRGB(253,124,103)));
    ListeGradFond.push_back(new OptionGrad(100,1,Svgfile::makeRGB(253,94,83)));
    Gradient G("linear",0,100,0,0,ListeGradFond);
    ListeObjet.push_back(new Fond(m_pos1,m_pos2,G));

    int nbr_Objet=util::alea(10,20,rg);

    for(int i=0;i<nbr_Objet;i++)
        ListeObjet.push_back(new Nuage(m_pos1,m_pos2,rg));
    std::vector <OptionGrad*> Liste; //AJOUTE GRADIENT SUR LES X NuageS
    Liste.push_back(new OptionGrad(30,1,Svgfile::makeRGB(253,124,103)));
    Liste.push_back(new OptionGrad(100,0,Svgfile::makeRGB(253,94,83))); //100 - BLANC
    Gradient H("linear",0,100,0,10,Liste);
    ListeObjet.push_back(new Fond(m_pos1,m_pos2,H));

    ListeObjet.push_back(new Soleil(m_pos1,m_pos2,rg,y_Soleil,r)); //+Y

    for(int i=0;i<nbr_Objet;i++)
        ListeObjet.push_back(new Nuage(m_pos1,m_pos2,rg));
}

