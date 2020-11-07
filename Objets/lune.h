/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file lune.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee lune \n
 * Sous-classe de objet \n
 */
#ifndef Lune_H
#define Lune_H

#include <objet.h>

///Objet
class Lune : public Objet
{
    public:
        Lune(Coords p1, Coords p2, std::mt19937& graine);
        Lune();

        virtual ~Lune();

    protected:

    private:
};

#endif // Lune_H
