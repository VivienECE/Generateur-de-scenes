/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file ellipse_gradient.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee ellipse_gradient \n
 * Sous-classe de ellipse \n
 * Contient 1 coord + 2 rayons (en X, en Y) + 1 Gradient \n
 */
#ifndef Ellipse_GRADIENT_H
#define Ellipse_GRADIENT_H

#include <Ellipse.h>

///Primitive
class Ellipse_gradient : public Ellipse
{
    public:
        Ellipse_gradient();
        Ellipse_gradient(double x,double y,double rx,double ry,Gradient G);
        Ellipse_gradient(double x,double y,double r,Gradient G);
        void dessiner(Svgfile& svgout) const;

    protected:
        Gradient m_gradient;
};

#endif // Ellipse_GRADIENT_H
