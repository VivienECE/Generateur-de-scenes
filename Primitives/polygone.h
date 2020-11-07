/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file polygone.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee polygone \n
 * Sous-classe de primitive \n
 * Contient une liste de Coords (x,y) + 1 couleur
 */
#ifndef Polygone_H
#define Polygone_H

#include "Primitive.h"
#include <vector>

///Primitive
class Polygone : public Primitive
{
    public:
        Polygone();
        ~Polygone();
        Polygone(std::vector <Coords*>& Liste,std::string couleur);
        void dessiner(Svgfile& svgout) const;

    protected:
        std::vector <Coords*> ListeSommet;
};

#endif // Polygone_H
