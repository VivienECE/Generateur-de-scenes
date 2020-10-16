///DETOURNAY-HILT-PICHON
#ifndef Polyline_H
#define Polyline_H

#include <Primitive.h>


class Polyline : public Primitive
{
    public:
        Polyline();
        ~Polyline();
        Polyline(std::vector <Coords*>& Liste,std::string couleur, double ep);
        Polyline(std::vector <Coords*>& Liste,std::string couleur, std::string couleur2, double ep);
        void dessiner(Svgfile& svgout) const;

    protected:
        std::vector <Coords*> ListeSommet;
        double m_ep;
        std::string m_couleur2="blank";
};

#endif // Polyline_H
