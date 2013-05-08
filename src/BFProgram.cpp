#include "../include/BFProgram.h"

using namespace std;

BFProgram::BFProgram()
{
    //for now, start with the basic hello world program:
    fitness = 0.0;
    code = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
}//BFProgram()

string BFProgram::execute()
{
    return execute("");
}//execute()
string BFProgram::mutate()
{
    return mutate(code);
}
string BFProgram::mutate(string toMutate)
{
    //TODO: Implement program mutation.
    //go through each character...
    return "";
}//mutate()

string BFProgram::execute(string input)
{
    //create a variable to hold the output
    string output = "";
    //setup the memory.
    char memArray[MEMSIZE];
    int memIndex = 0;
    //setup an input index
    int inputIndex = 0;
    //setup a step counter
    int currentStep = 0;
    //start execution
    for(int a=0; a<code.length(); a++)
    {
        //increment the current step we're on.
        currentStep++;
        //have we reached our limit?
        if(currentStep > MAXSTEPS)
        {
            throw "Program timed-out.";
        }
        //what instruction are we running?
        char instruct = code[a];
        switch(instruct)
        {
        case '>':
            //shift pointer to the right
            memIndex++;
            if(memIndex >= MEMSIZE)
            {
                throw "Memory address out of bounds.";
            }
            break;
        case '<':
            //shift pointer to the left
            memIndex--;
            if(memIndex <0 )
            {
                throw "Memory address out of bounds.";
            }
            break;
        case '+':
            //increment the memory at pointer
            memArray[memIndex]++;
            break;
        case '-':
            //decrement the memory at pointer
            memArray[memIndex]--;
            break;
        case '.':
            //output the memory at pointer
            output += memArray[memIndex];
            break;
        case ',':
            if(inputIndex >= input.length())
            {
                throw "Input index out of bounds.";
            }
            memArray[memIndex] = input[inputIndex];
            inputIndex++;
            break;
        case '[':
            //if memory is 0, go to matching ]
            if(memArray[memIndex]==0)
            {
                while(code[a]!= ']')
                {
                    a++;
                    if(a >= code.length())
                    {
                        throw "Unmatched bracket '['";
                    }
                }
            }//if(*ptr==0)
            break;
        case ']':
            //if memory isn't 0, go back to matching [
            if(memArray[memIndex]!=0)
            {
                while(code[a] != '[')
                {
                    a--;
                    if(a<0)
                    {
                        throw "Unmatched bracket ']'";
                    }
                }
            }//if(*ptr!=0)

        }//switch(instruct)
    }//for(a=0;a<code.length; a++

    return output;
}//execute(string)
