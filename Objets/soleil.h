/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file soleil.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee soleil \n
 * Sous-classe de objet \n
 */
#ifndef Soleil_H
#define Soleil_H

#include <Objet.h>

///Objet
class Soleil : public Objet
{
    public:
        Soleil(Coords p1, Coords p2, std::mt19937& graine, double y, double r);
        virtual ~Soleil();

    protected:

    private:
};

#endif // Soleil_H
