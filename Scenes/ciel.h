/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file ciel.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Super-classe ciel \n
 * Sous-classe de plan \n
 * Contient plusieurs objets "nuage","etoile","lune","soleil"
 */
#ifndef Ciel_H
#define Ciel_H

#include <Plan.h>

///Plan

class Ciel : public Plan
{
    public:
        Ciel(double y1, double y2);

};

#endif // Ciel_H
