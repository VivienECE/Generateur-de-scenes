///DETOURNAY-HILT-PICHON
#ifndef Fond_H
#define Fond_H

#include <Objet.h>

//Fond du Plan
class Fond : public Objet
{
    public:
        Fond(Coords p1, Coords p2, std::string couleur);
        Fond(std::vector <Coords*>& L, std::string couleur);
        Fond(Coords p1, Coords p2, Gradient G);
        virtual ~Fond();

    protected:

    private:
};

#endif // Fond_H
