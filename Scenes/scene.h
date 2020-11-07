/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file scene.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe Scene \n
 * Contient plusieurs objets de classe plans \n
 *
 * 3 schemas type d'une scene : \n
 * -1er plan:plan_eau, 2nd plan: plaine, 3eme plan:ciel \n
 * -1er plan:relief, 2nd plan: plan_eau, 3eme plan:ciel \n
 * -1er plan:plaine, 2nd plan: plan_eau, 3eme plan:relief, 4eme plan:ciel
 */
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

/// Ensemble de plans
class Scene
{
    private:
        std::vector <Plan*> ListePlans;

    public:
        Scene(int graine, int choix[1]);

        /**
        * @brief Dessine la scene dans le fichier svg en parametre
        * @param svgout Fichier svg
        */
        void dessiner(Svgfile& svgout) const;

};

#endif // SCENE_H_INCLUDED
