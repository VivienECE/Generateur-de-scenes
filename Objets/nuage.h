/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file nuage.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee nuage \n
 * Sous-classe de objet \n
 */
#ifndef Nuage_H
#define Nuage_H

#include <Objet.h>

///Objet
class Nuage : public Objet
{
    public:
        Nuage(Coords p1, Coords p2, std::mt19937& graine);

    private:
};

#endif // Nuage_H
