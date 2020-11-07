/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file plaine.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe dérivée plaine \n
 * Sous-classe de plan \n
 * Contient plusieurs objets "herbe"
 */
#ifndef Plaine_H
#define Plaine_H

#include "Plan.h"

///Plan
class Plaine : public Plan
{
    public:
        Plaine(double y1, double y2,std::mt19937& rg);

};

#endif // Plaine_H
