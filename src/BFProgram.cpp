#include "../include/BFProgram.h"

using namespace std;

BFProgram::BFProgram()
{
    //for now, start with the basic hello world program:
    code = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
}//BFProgram()

string BFProgram::execute()
{
    return execute("");
}//execute()

string BFProgram::execute(string input)
{
    //create a variable to hold the output
    string output = "";
    //setup the memory.
    char memArray[30000];
    char *ptr = memArray;
    //start execution
    for(int a=0; a<code.length(); a++)
    {
        //what instruction are we running?
        char instruct = code[a];
        switch(instruct)
        {
            case '>':
                //shift pointer to the right
                ++ptr;
                break;
            case '<':
                //shift pointer to the left
                --ptr;
                break;
            case '+':
                //increment the memory at pointer
                ++*ptr;
                break;
            case '-':
                //decrement the memory at pointer
                --*ptr;
                break;
            case '.':
                //output the memory at pointer
                output += *ptr;
                break;
            case ',':
                //TODO: implement input
                break;
            case '[':
                //if memory is 0, go to matching ]
                if(*ptr==0)
                {
                    //TODO: Prevent segfaults from non-matched bracket
                    while(code[a]!= ']'){
                        a++;
                    }
                }//if(*ptr==0)
                break;
            case ']':
                //if memory isn't 0, go back to matching [
                if(*ptr!=0)
                {
                    //TODO: prevent segfault from unmatched ]
                    while(code[a] != '['){
                        a--;
                    }
                }//if(*ptr!=0)

        }//switch(instruct)
    }//for(a=0;a<code.length; a++

    return output;
}//execute(string)
