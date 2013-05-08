#include "../include/BFProgram.h"

using namespace std;

BFProgram::BFProgram()
{
    //for now, start with the basic hello world program:
    code = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
}//BFProgram()

string BFProgram::execute(string input)
{
    string output = "Hello world";

    return output;
}//execute()
