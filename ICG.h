#ifndef ICG_H
#define ICG_H
#include <map>
#include "lexer.h"

class ICG{
    public:
        ICG(Lexer* lex);
    private:
        Lexer* lexer;

};



#endif