#ifndef GENEPOOL_H
#define GENEPOOL_H
#include "BFProgram.h"
#include <string>

const int POOLSIZE = 100;

class GenePool
{
    public:
        GenePool();
        ~GenePool();
        float measureFitness(std::string, std::string);
        void testGeneration();
        void pollGeneration();
    private:
        BFProgram* programPool;
};

#endif // GENEPOOL_H
