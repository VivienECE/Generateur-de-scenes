/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file plan.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Super-classe Plan \n
 * Un plan contient plusieurs "Objets" (etoile, herbe, montagne...)
 */
#ifndef Plan_H_INCLUDED
#define Plan_H_INCLUDED
#include <iostream>
#include <algorithm>
#include "../Objets/Coords.h"
#include "../Objets/Objet.h"
#include "../Objets/Herbe.h"
#include "../Objets/Montagne.h"
#include "../Objets/Vague.h"
#include "../Objets/Fond.h"
#include "../Objets/Nuage.h"
#include "../Objets/Soleil.h"
#include <Etoile.h>
#include <Etoilefilante.h>
#include <Lune.h>

/// Ensemble d'objets
class Plan
{
    protected:
        Coords m_pos1;
        Coords m_pos2;
        std::vector<Objet*> ListeObjet;

    public:
        Plan(double y1, double y2); //y1/y2 Ordonnée haute/basse du plan
        virtual ~Plan();
        virtual void dessiner(Svgfile& svgout) const;
        virtual void homothetie();
};



#endif // Plan_H_INCLUDED
