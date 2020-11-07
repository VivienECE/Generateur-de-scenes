/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file montagne.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee montagne \n
 * Sous-classe de objet \n
 */
#ifndef Montagne_H
#define Montagne_H

#include <Objet.h>

///Objet
class Montagne : public Objet
{
    public:
        Montagne(Coords p1, Coords p2, std::mt19937& graine);
        bool operator <(const Objet&G1);

    protected:

    private:
};



#endif // Montagne_H
