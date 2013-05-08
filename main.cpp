#include <iostream>
#include "include/GenePool.h"

using namespace std;

int main()
{
    GenePool gp;
    gp.testGeneration();
    cout<<gp.getReport()<<endl;
    return 0;
}

