///DETOURNAY-HILT-PICHON
#ifndef Vague_H_INCLUDED
#define Vague_H_INCLUDED

#include <Objet.h>


class Vague : public Objet
{
    public:
        Vague(Coords p1, Coords p2, std::mt19937& graine);
        bool operator <(const Objet&G1);

    protected:

    private:
};


#endif // Vague_H_INCLUDED
