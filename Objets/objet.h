///DETOURNAY-HILT-PICHON
#ifndef Objet_H_INCLUDED
#define Objet_H_INCLUDED
#include <vector>
#include <fstream>
#include "../Svg/svgfile.h"
#include "../Primitives/Primitive.h"
#include "../Aleatoire/util.h"
#include <Disk.h>
#include <line.h>
#include <Triangle.h>
#include <Polygone.h>
#include <Ellipse.h>
#include <Polyline.h>
#include <Ellipse_gradient.h>
#include <Ellipse_gradient_animated.h>
#include <Polygone_gradient.h>
#include <tronc.h>
#include "iostream"

class Coords;
class Primitive;
class Objet
{
    protected: //->DIFF Objet BATEAU/VAISSEAU/ARBRE..JSP + differente couleur tt sa...
        Coords m_position;
        std::vector <Primitive*> ListePrimitives;

    public:
        Objet();
        Objet(Coords pos1, Coords pos2);
        virtual ~Objet();
        virtual void dessiner(Svgfile& svgout) const;
        virtual void homothetie(float coef);
        double getY() const;
        double getX() const;
        virtual bool operator <(const Objet& G1);
};

///RENVOIE TRUE SI (x,y) COMPRIS DANS LE POLYGONE (FERMEE) DEFINIE PAR LA LISTE, FALSE SINON
bool coords_in_polygon(double x, double y, std::vector <Coords*>& Liste);



#endif // Objet_H_INCLUDED
