#ifndef GENEPOOL_H
#define GENEPOOL_H
#include "BFProgram.h"

const int POOLSIZE = 100;

class GenePool
{
    public:
        GenePool();
        ~GenePool();
    private:
        BFProgram* programPool;
};

#endif // GENEPOOL_H
