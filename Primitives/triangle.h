/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file triangle.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee Triangle \n
 * Sous-classe de primitive \n
 * Contient 3 Coords (x,y) + 1 couleur
 */
#ifndef Triangle_H
#define Triangle_H

#include "Primitive.h"

///Primitive
class Triangle : public Primitive
{
    public:
        Triangle();
        Triangle(Coords pos1, Coords pos2, Coords pos3, std::string couleur);
        void dessiner(Svgfile& svgout) const;
        void homothetie(double coef);

    protected:
        Coords m_position1;
        Coords m_position2;
        Coords m_position3;

};

#endif // Triangle_H
