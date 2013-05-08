#ifndef BFPROGRAM_H
#define BFPROGRAM_H

#include <string>

class BFProgram
{
    public:
        BFProgram();
        std::string execute(std::string);
    private:
        std::string code;
};

#endif // BFPROGRAM_H
