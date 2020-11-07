/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file line.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee line \n
 * Sous-classe de primitive \n
 * Contient 2 coords + 1 couleur \n
 */
#ifndef Line_H
#define Line_H

#include "Primitive.h"

///Primitive
class Line : public Primitive
{
    public:
        Line();
        Line(Coords pos1, Coords pos2, std::string couleur);
        void dessiner(Svgfile& svgout) const;

    protected:
        Coords m_position1;
        Coords m_position2;

};

#endif // Line_H
