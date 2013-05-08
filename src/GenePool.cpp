#include "../include/GenePool.h"
#include "../include/BFProgram.h"

using namespace std;

GenePool::GenePool()
{
    programPool = new BFProgram[POOLSIZE];
}//GenePool()


GenePool::~GenePool()
{
    delete [] programPool;
}//~GenePool()

float GenePool::measureFitness(string expectedOutput, string actualOutput)
{
    //TODO: Implement fitness measuring.
    return 0.0;
}

void GenePool::testGeneration()
{
    //TODO: Implement test for current generation
}//testGeneration()
void GenePool::pollGeneration()
{
    //TODO: Implement polling for the next generation
}//pollGeneration()
