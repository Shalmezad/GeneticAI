#ifndef BFPROGRAM_H
#define BFPROGRAM_H

#include <string>

const int MEMSIZE = 30000;

class BFProgram
{
    public:
        BFProgram();
        std::string execute();
        std::string execute(std::string);
    private:
        std::string code;
};

#endif // BFPROGRAM_H
