#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "lexer.h"

class Interpreter
{
    public:
        Interpreter(Lexer* l);

    private:
        Lexer* lexer;
        int memory[999]; // TODO: find default value? :D
        int pos=0;
};

#endif