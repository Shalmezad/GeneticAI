#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "include/GenePool.h"

using namespace std;

int main()
{
    //seed the RNG:
    srand (time(NULL));
    GenePool gp;
    gp.testGeneration();
    cout<<gp.getReport();
    return 0;
}

