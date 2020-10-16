#include "Primitive.h"
#include "iostream"
Primitive::Primitive()
{

}

Primitive::Primitive(std::string couleur): m_couleur{couleur}
{}

Primitive::~Primitive()
{

}

void Primitive::dessiner(Svgfile& svgout) const
{

}

void Primitive::homothetie(double coef)
{

}
