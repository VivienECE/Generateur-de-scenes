#include "Plan_eau.h"

Plan_eau::Plan_eau(double x, double y, std::mt19937& rg):Plan(x,y)
{
    int nbr_Objet=util::alea(200,1000,rg);
    for(int i=0;i<nbr_Objet;i++)
    {
        ListeObjet.push_back(new Vague{m_pos1,m_pos2,rg}); //ADD m_pos1/2 comme délimitation de la gen.des objs
    }
    std::sort (ListeObjet.begin(), ListeObjet.end(), [](Objet* G1 , Objet* G2) { return *G1 < *G2;} );
}

