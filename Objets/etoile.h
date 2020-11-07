/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file etoile.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee etoile \n
 * Sous-classe de objet \n
 */
#ifndef Etoile_H
#define Etoile_H

#include <objet.h>

///Objet
class Etoile : public Objet
{
    public:
        Etoile(Coords p1, Coords p2, std::mt19937& graine);
        Etoile();
        virtual ~Etoile();


    protected:

    private:
};

#endif // Etoile_H
