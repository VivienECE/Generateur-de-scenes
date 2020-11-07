/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file etoilefilante.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee etoilefilante \n
 * Sous-classe de objet \n
 */
#ifndef EtoileFILANTE_H_INCLUDED
#define EtoileFILANTE_H_INCLUDED

#include <objet.h>

///Objet
class Etoilefilante : public Objet
{
    public:
        Etoilefilante(Coords p1, Coords p2, std::mt19937& graine);

        Etoilefilante();
        virtual ~Etoilefilante();


    protected:

    private:
};


#endif // EtoileFILANTE_H_INCLUDED
