/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file ellipse.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee ellipse \n
 * Sous-classe de primitive \n
 * Contient 1 coords + 2 rayons (en X, en Y) + 1 couleur \n
 */
#ifndef Ellipse_H
#define Ellipse_H

#include <Primitive.h>

///Primitive
class Ellipse : public Primitive
{
    public:
        virtual ~Ellipse();
        Ellipse();
        Ellipse(double x,double y,double rx,double ry,std::string couleur);
        virtual void dessiner(Svgfile& svgout) const;

    protected:
        double m_x,m_y,m_rx,m_ry;
};

#endif // Ellipse_H
