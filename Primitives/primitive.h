/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file primitive.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Super-classe Primitive \n
 * Représentation graphique simple composee de coordonnees (x,y) et d'une couleur.
 */
#ifndef Primitive_H_INCLUDED
#define Primitive_H_INCLUDED
#include "../Svg/svgfile.h"
#include <string>
#include "../Objets/Coords.h"

/// Figure composee d'un ensemble de coordonnees et d'une couleur/gradient
class Primitive
{
    protected:
        std::string m_couleur;

    public:
        Primitive();
        Primitive(std::string couleur);
        virtual ~Primitive();
        virtual void dessiner(Svgfile& svgout) const;
        virtual void homothetie(double coef);

};


#endif // Primitive_H_INCLUDED
