///DETOURNAY-HILT-PICHON
#ifndef Relief_H
#define Relief_H
#include "Plan.h"

class Relief : public Plan
{
    public:
        Relief(double y1, double y2,std::mt19937& rg);

};

#endif // Relief_H
