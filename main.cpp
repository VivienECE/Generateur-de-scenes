#include <iostream>
#include "Svg/svgfile.h"
#include "scene.h"
#include <complex>


int main()
{
    int choix,graine;
    int choixscene[1];

    std::cout << "0->Quitter"<< std::endl
    << "1->Generation aleatoire" << std::endl
    << "2->Generation avec parametres et graine" << std::endl
    << "3->Generation rapide selon les parametres" << std::endl;

    while(choix!=0)
    {
        std::cin >> choix;
        switch(choix)
        {
            case 1:
            {
                choixscene[0]=-1;
                Svgfile svgout;
                Scene Sc(-1,choixscene);
                Sc.dessiner(svgout);
                std::cout << "Scene aleatoire genere" <<std::endl;
                break;
            }
            case 2:
            {
                std::cout << "Numero graine:";
                std::cin >> graine;
                std::cout << "Jour 0, Soir 1, Nuit 2:";
                std::cin >> choixscene[0];
                std::cout << "Scene 0, Scene 1, Scene 2:";
                std::cin >> choixscene[1];

                Svgfile svgout;
                Scene Sc(graine, choixscene);
                Sc.dessiner(svgout);
                std::cout << "Scene genere" <<std::endl;
                break;
            }
            case 3:
            {
                Svgfile svgout;
                Scene Sc(-1,choixscene);
                Sc.dessiner(svgout);
                std::cout << "Scene aleatoire genere" <<std::endl;
                break;
            }
        }
    }
    return 0;
}

