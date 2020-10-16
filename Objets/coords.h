///DETOURNAY-HILT-PICHON
#ifndef Coords_H_INCLUDED
#define Coords_H_INCLUDED

class Coords
{
    public :
        Coords(double x, double y);
        Coords();

        void afficher() const;
        void saisir();

        double getX() const;
        double getY() const;

        friend Coords operator+(const Coords& c1, const Coords& c2);
        void setCoord(double x, double y);
        ///Remplace les coords par x et y
        void addCoord(double x, double y);
        ///Ajoute +x, +y respectivement aux coords

    private :
        double m_x;
        double m_y;
};


#endif // Coords_H_INCLUDED
