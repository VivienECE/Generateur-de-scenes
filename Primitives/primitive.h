///DETOURNAY-HILT-PICHON
#ifndef Primitive_H_INCLUDED
#define Primitive_H_INCLUDED
#include "../Svg/svgfile.h"
#include <string>
#include "../Objets/Coords.h"

class Primitive
{
    protected:
        std::string m_couleur;

    public:
        Primitive();
        Primitive(std::string couleur);
        virtual ~Primitive();
        virtual void dessiner(Svgfile& svgout) const;
        virtual void homothetie(double coef);

};


#endif // Primitive_H_INCLUDED
