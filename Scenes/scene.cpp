#include "scene.h"

Scene::Scene(int graine, int choix[1])
{
    if(graine==-1)
        graine=util::alea(5000,10000);
    std::mt19937 rg{graine};
    if(choix[0]==-1)
    {
        choix[0]=util::alea(0,2,rg); //3 TYPES DE Ciel
        choix[1]=util::alea(0,2,rg); //3 TYPES DE SCENE
    }

    switch (choix[0])
    {
        case 0:
            if(choix[1]==0)
                ListePlans.push_back(new Jour(0,400,rg));
            if(choix[1]==1)
                ListePlans.push_back(new Jour(0,600,rg));
            if(choix[1]==2)
                ListePlans.push_back(new Jour(0,500,rg));
            break;
        case 1:
            if(choix[1]==0)
                ListePlans.push_back(new Soir(0,400,rg));
            if(choix[1]==1)
                ListePlans.push_back(new Soir(0,600,rg));
            if(choix[1]==2)
                ListePlans.push_back(new Soir(0,500,rg));
            break;
        case 2:
            if(choix[1]==0)
                ListePlans.push_back(new Nuit(0,400,rg));
            if(choix[1]==1)
                ListePlans.push_back(new Nuit(0,600,rg));
            if(choix[1]==2)
                ListePlans.push_back(new Nuit(0,500,rg));
            break;
    }
    switch (choix[1])
    {
        case 0:
            ListePlans.push_back(new Plan_eau(400,800,rg));
            ListePlans.push_back(new Relief(400,800,rg));
        break;

        case 1:
            ListePlans.push_back(new Relief(300,600,rg));
            ListePlans.push_back(new Plaine(600,800,rg));
            ListePlans[2]->homothetie();
        break;

        case 2:
            ListePlans.push_back(new Relief(300,500,rg));
            ListePlans.push_back(new Plan_eau(500,650,rg));
            ListePlans.push_back(new Plaine(650,800,rg));
        break;
    }
    // /!\ Ajoute d'abord les Plans les + HAUT.
}

void Scene::dessiner(Svgfile& svgout) const
{
    for(const auto& i:ListePlans)
        i->dessiner(svgout);
}



