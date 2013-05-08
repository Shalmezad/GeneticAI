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
    //first, what are we testing?
    Test generationTest = makeTest();
    //next, create variables to store the result and fitness
    string programOutput;
    float programFitness;
    //cycle through each program.
    for(int a=0; a<POOLSIZE; a++){
        try
        {
            //run the program
            programOutput = programPool[a].execute(generationTest.input);
            //now measure the fitness.
            programFitness = measureFitness(generationTest.output, programOutput);
            //and set the program fitness.
            programPool[a].setFitness(programFitness);
        }//try
        catch(const char *e){
            //Program errored. Fitness is 0.
            programPool[a].setFitness(0.0);
        }//catch(const char *e)
    }//for(int a=0; a<POOLSIZE; a++)
}//testGeneration()
void GenePool::pollGeneration()
{
    //TODO: Implement polling for the next generation
}//pollGeneration()

Test GenePool::makeTest()
{
    Test newTest;
    newTest.input = "";
    newTest.output = "Hi";
    return newTest;
}
