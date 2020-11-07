/****************************************************************************
 * Copyright (C) 2020 by Vivien DETOURNAY, Florian HILT, Gauthier PICHON    *
 ****************************************************************************/

/**
 * @file plan_eau.h
 * @author Vivien
 * @date 07 Nov 2020
 * @brief
 * Classe dérivée Plan_eau \n
 * Sous-classe de plan \n
 * Contient plusieurs objets "vague"
 */
#ifndef Plan_EAU_H
#define Plan_EAU_H

#include <Plan.h>

///Plan
class Plan_eau : public Plan
{
    public:
        Plan_eau(double y1, double y2,std::mt19937& rg);

    protected:

    private:
};

#endif // Plan_EAU_H
