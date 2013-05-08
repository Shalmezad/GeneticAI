#ifndef GENEPOOL_H
#define GENEPOOL_H
#include "BFProgram.h"
#include <string>

const int POOLSIZE = 100;

struct Test
{
    std::string input;
    std::string output;
};

class GenePool
{
public:
    GenePool();
    ~GenePool();
    float measureFitness(std::string, std::string);
    void testGeneration();
    void pollGeneration();
    Test makeTest();
    std::string getReport();
    float getTotalFitness();
private:
    BFProgram* programPool;
};

#endif // GENEPOOL_H
