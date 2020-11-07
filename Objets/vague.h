/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file vague.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee vague \n
 * Sous-classe de objet \n
 */
#ifndef Vague_H_INCLUDED
#define Vague_H_INCLUDED

#include <Objet.h>

///Objet
class Vague : public Objet
{
    public:
        Vague(Coords p1, Coords p2, std::mt19937& graine);
        bool operator <(const Objet&G1);

    protected:

    private:
};


#endif // Vague_H_INCLUDED
