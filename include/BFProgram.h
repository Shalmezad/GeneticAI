#ifndef BFPROGRAM_H
#define BFPROGRAM_H

#include <string>

const int MEMSIZE = 30000;
const int MAXSTEPS = 30000;

class BFProgram
{
public:
    BFProgram();
    std::string execute();
    std::string execute(std::string);
    float getFitness()
    {
        return fitness;
    }
    void setFitness(float f)
    {
        fitness = f;
    }
    std::string getCode()
    {
        return code;
    }
    void setCode(std::string s)
    {
        code = s;
    }
    std::string mutate();
    std::string mutate(std::string);
private:
    std::string code;
    float fitness;
};

#endif // BFPROGRAM_H
