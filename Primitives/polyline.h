/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file polyline.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee Polyline \n
 * Sous-classe de primitive \n
 * Contient une liste de coords (x,y) + 1 couleur + 1 epaisseur
 */
#ifndef Polyline_H
#define Polyline_H

#include <Primitive.h>

///Primitive
class Polyline : public Primitive
{
    public:
        Polyline();
        ~Polyline();
        Polyline(std::vector <Coords*>& Liste,std::string couleur, double ep);
        Polyline(std::vector <Coords*>& Liste,std::string couleur, std::string couleur2, double ep);
        void dessiner(Svgfile& svgout) const;

    protected:
        std::vector <Coords*> ListeSommet;
        double m_ep;
        std::string m_couleur2="blank";
};

#endif // Polyline_H
