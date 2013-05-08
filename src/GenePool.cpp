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
}//measureFitness(string, string)

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
    //For now:
    //Find a BF program to write the given message.
    //Create a test
    Test newTest;
    //no input
    newTest.input = "";
    //we want a given message
    newTest.output = "Hi";
    return newTest;
}//makeTest()

string GenePool::getReport()
{
    //display a report on the current generation.
    string report = "";
    //TODO: Add variables to the report.
    report += "Average fitness: ";
    report += "Best fitness: ";
    report += "Best program: ";
    report += "Best program output: ";

    return report;
}//getReport()
