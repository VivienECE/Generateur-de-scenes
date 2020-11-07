/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file disk.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee disk \n
 * Sous-classe de primitive \n
 * Contient 1 coords + 1 rayons + 1 couleur \n
 */
#ifndef Disk_H
#define Disk_H

#include "Primitive.h"

///Primitive
class Disk : public Primitive
{
    public:
        Disk();
        Disk(Coords centre, double r, std::string couleur);
        void dessiner(Svgfile& svgout) const;

    protected:
        Coords m_centre;
        double m_rayon;
};

#endif // Disk_H
