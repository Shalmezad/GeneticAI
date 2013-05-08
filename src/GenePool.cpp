#include "../include/GenePool.h"
#include "../include/BFProgram.h"
#include <iostream>

using namespace std;

GenePool::GenePool()
{
    programPool = new BFProgram[POOLSIZE];
    cout<<"Pool created."<<endl;
}//GenePool()


GenePool::~GenePool()
{
    delete [] programPool;
    cout<<"Pool deleted."<<endl;
}//~GenePool()
