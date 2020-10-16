#include "Plaine.h"
Plaine::Plaine(double x, double y,std::mt19937& rg) : Plan(x,y)
{
    //ListeObjet.push_back(new Fond(m_pos1,m_pos2,Svgfile::makeRGB(126,51,0)));//Fond MARRON
    ListeObjet.push_back(new Fond(m_pos1,m_pos2,Svgfile::makeRGB(27, 79, 8)));

    int nbr_Objet=util::alea(30000,33000,rg);
    for(int i=0;i<nbr_Objet;i++)
    {
        ListeObjet.push_back(new Herbe{m_pos1,m_pos2,rg}); //Herbes
    }
    std::sort (ListeObjet.begin(), ListeObjet.end(), [](Objet* G1 , Objet* G2) { return *G1 < *G2;} );

}
