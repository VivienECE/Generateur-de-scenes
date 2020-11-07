/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file polygone_gradient.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee polygone_gradient \n
 * Sous-classe de polygone \n
 * Contient une liste de Coords (x,y) + 1 gradient
 */
#ifndef Polygone_GRADIENT_H
#define Polygone_GRADIENT_H

#include <Polygone.h>

///Primitive
class Polygone_gradient : public Polygone
{
    public:
        Polygone_gradient();
        virtual ~Polygone_gradient();
        Polygone_gradient(std::vector <Coords*>& Liste, Gradient G);
        void dessiner(Svgfile& svgout) const;
    protected:
        Gradient m_gradient;
};

#endif // Polygone_GRADIENT_H
