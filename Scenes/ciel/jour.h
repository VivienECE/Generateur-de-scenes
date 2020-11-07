/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file jour.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee jour \n
 * Sous-classe de ciel \n
 * Contient plusieurs objets "nuage", et un objet "soleil"
 */
#ifndef Jour_H
#define Jour_H

#include <Ciel.h>

///Ciel
class Jour : public Ciel
{
    public:
        Jour(double y1, double y2,std::mt19937& rg);
};

#endif // Jour_H
