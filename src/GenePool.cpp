#include "../include/GenePool.h"
#include "../include/BFProgram.h"

#include <stdlib.h>
#include <sstream>

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
    //Alright, we have 2 strings, we want to see how similar they are.
    //Specifically, how close the actual output was to the expected output
    //(whether our test matched what we wanted).
    //http://en.wikipedia.org/wiki/Category:String_similarity_measures
    //Specifically, I'm going to use the bonacci distnace.

    //First, if either string is len=0, return.
    int s1 = expectedOutput.length();
    int s2 = actualOutput.length();
    if(s1 == 0 || s2==0)
    {
        return 0.0;
    }//if(s1==0 || s2==0)

    //The max allowable distance between 2 characters is (max(l1, l2)/2)-1
    float maxDistance = max(s1,s2)/2-1;
    int m = 0;

    //cycle through the first string
    for(int a=0; a<s1; a++){
        //cycle through the second string.
        for(int b=0; b<s2; b++){
            //are we less than the max allowed distance?
            if(abs(a-b) < maxDistance){
                //check the characters:
                if(expectedOutput[a] == actualOutput[b]){
                    //if a match, increment.
                    m++;
                    break;
                }
            }
        }
    }

    //At this point, if matched characters = 0, return 0.
    if(m == 0){
        return 0.0;
    }//if(matchedCharacters == 0)

    //If not, do the calculation.
    //1/3 (m/s1 + m/s2 + m-t/m)
    //TODO: Add t to the equation.
    return .5 * ((float)m/s1 + (float)m/s2);
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

float GenePool::getTotalFitness()
{
    float total = 0.0;
    for(int i=0; i<POOLSIZE; i++){
        total += programPool[i].getFitness();
    }
    return total;
}//getTotalFitness()

Test GenePool::makeTest()
{
    //For now:
    //Find a BF program to write the given message.
    //Create a test
    Test newTest;
    //no input
    newTest.input = "";
    //we want a given message
    newTest.output = "Hello";
    return newTest;
}//makeTest()

string GenePool::getReport()
{
    //display a report on the current generation.
    string report = "";
    stringstream ss (stringstream::in | stringstream::out);
    //TODO: Add variables to the report.
    ss<< "Average fitness: ";
    ss<< (getTotalFitness()/POOLSIZE)<<endl;
    ss<< "Best fitness: "<<endl;
    ss<< "Best program: "<<endl;
    ss<< "Best program output: "<<endl;

    return ss.str();
}//getReport()
