/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file fond.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee fond \n
 * Sous-classe de objet \n
 */
#ifndef Fond_H
#define Fond_H

#include <Objet.h>

///Objet
class Fond : public Objet
{
    public:
        Fond(Coords p1, Coords p2, std::string couleur);
        Fond(std::vector <Coords*>& L, std::string couleur);
        Fond(Coords p1, Coords p2, Gradient G);
        virtual ~Fond();

    protected:

    private:
};

#endif // Fond_H
