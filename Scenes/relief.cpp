#include "Relief.h"

Relief::Relief(double x, double y,std::mt19937& rg) : Plan(x,y)
{
    int nbr_Objet=util::alea(2,5,rg); //Ajoute 1 Montagne vu que sa prend tt le Plan.
    for(int i=0;i<nbr_Objet;i++)
    {
        ListeObjet.push_back(new Montagne{m_pos1,m_pos2,rg}); //ADD m_pos1/2 comme délimitation de la gen.des objs
    }
    std::sort (ListeObjet.begin(), ListeObjet.end(), [](Objet* G1 , Objet* G2) { return *G1 < *G2;} );
}

