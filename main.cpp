#include <iostream>
#include "include/GenePool.h"

using namespace std;

void testFitnessMeasure();

int main()
{
    testFitnessMeasure();
    return 0;
}

void testFitnessMeasure()
{
    cout<<"Testing fitness measurement: "<<endl;
    cout<<"Creating a genepool..."<<endl;
    GenePool gp;
    //run tests
    cout<<"Test: MARTHA, MARHTA (.944): ";
    cout<<gp.measureFitness("MARTHA", "MARHTA")<<endl;
    cout<<"Test: DWAYNE, DUANE (.822): ";
    cout<<gp.measureFitness("DWAYNE", "DUANE")<<endl;
}//testFitnessMeasure()
