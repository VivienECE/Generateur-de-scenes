/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file soir.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe derivee soir \n
 * Sous-classe de plan \n
 * Contient plusieurs objets "nuage" et un objet "soleil"
 */
#ifndef Soir_H
#define Soir_H

#include <Ciel.h>

///Ciel
class Soir : public Ciel
{
    public:
        Soir(double y1, double y2,std::mt19937& rg);

};

#endif // Soir_H
