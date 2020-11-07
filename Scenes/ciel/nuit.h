/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file nuit.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee nuit \n
 * Sous-classe de plan \n
 * Contient plusieurs objets "etoile" et un objet "lune" et aléatoirement 0 ou 1 "etoilefilante"
 */
#ifndef Nuit_H
#define Nuit_H

#include <Ciel.h>
///Ciel
class Nuit : public Ciel
{
    public:
        Nuit(double y1, double y2,std::mt19937& rg);
};

#endif // Nuit_H
