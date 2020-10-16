///DETOURNAY-HILT-PICHON
#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include "Plan.h"
#include "Plan_eau.h"
#include "Relief.h"
#include "Plaine.h"
#include "Ciel.h"
#include "effet.h"
#include "Jour.h"
#include "Nuit.h"
#include "Soir.h"
class Scene
{
    private:
        std::vector <Plan*> ListePlans;

    public:
        Scene(int graine, int choix[1]);
        void dessiner(Svgfile& svgout) const;

};

#endif // SCENE_H_INCLUDED
