#include "Plan.h"
#include <random>
#include <iostream>
#include <time.h>
#include "iostream"

Plan::Plan(double y1, double y2): m_pos1(-10,y1), m_pos2(810,y2) //+Grand que le svgfile pour meilleur effet (abscisse)
{

}

Plan::~Plan()
{

}

void Plan::dessiner(Svgfile& svgout) const
{
    for(const auto& i:ListeObjet)
        i->dessiner(svgout);
}

void Plan::homothetie() //Homothetie Plan par Plan
{
    float coef=0; //Coef->0 Objets grand, Coef->1 Objets Minuscule
    for(const auto& i:ListeObjet)
    {
        coef=1.6-(i->getY()/800); //1.6 Choisis arbitrairement.
        i->homothetie(coef);
    }
}






