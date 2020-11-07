/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file relief.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe dérivée relief \n
 * Sous-classe de plan \n
 * Contient plusieurs objets "montagnes"
 */
#ifndef Relief_H
#define Relief_H
#include "Plan.h"
///Plan
class Relief : public Plan
{
    public:
        Relief(double y1, double y2,std::mt19937& rg);

};

#endif // Relief_H
