/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file herbe.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee herbe \n
 * Sous-classe de objet \n
 */
#ifndef Herbe_H
#define Herbe_H

#include <Objet.h>

///Objet
class Herbe : public Objet
{
    public:
        Herbe();
        Herbe(Coords p1, Coords p2, std::mt19937& graine);
        Herbe(std::vector <Coords*>& Liste, std::mt19937& graine);
        bool operator <(const Objet&G1);
};

#endif // Herbe_H
