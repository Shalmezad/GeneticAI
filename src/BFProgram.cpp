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
    char memArray[MEMSIZE];
    int memIndex = 0;
    //start execution
    for(int a=0; a<code.length(); a++)
    {
        //what instruction are we running?
        char instruct = code[a];
        switch(instruct)
        {
            case '>':
                //shift pointer to the right
                memIndex++;
                break;
            case '<':
                //shift pointer to the left
                memIndex--;
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
                //TODO: implement input
                break;
            case '[':
                //if memory is 0, go to matching ]
                if(memArray[memIndex]==0)
                {
                    while(code[a]!= ']'){
                        a++;
                        if(a >= code.length()){
                            throw "Unmatched bracket '['";
                        }
                    }
                }//if(*ptr==0)
                break;
            case ']':
                //if memory isn't 0, go back to matching [
                if(memArray[memIndex]!=0)
                {
                    while(code[a] != '['){
                        a--;
                        if(a<0){
                            throw "Unmatched bracket ']'";
                        }
                    }
                }//if(*ptr!=0)

        }//switch(instruct)
    }//for(a=0;a<code.length; a++

    return output;
}//execute(string)
