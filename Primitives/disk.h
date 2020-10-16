///DETOURNAY-HILT-PICHON
#ifndef Disk_H
#define Disk_H

#include "Primitive.h"

class Disk : public Primitive
{
    public:
        Disk();
        Disk(Coords centre, double r, std::string couleur);
        void dessiner(Svgfile& svgout) const;

    protected:
        Coords m_centre;
        double m_rayon;
};

#endif // Disk_H
