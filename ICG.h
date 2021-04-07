#ifndef ICG_H
#define ICG_H
#include <map>
#include "lexer.h"

class ICG{
    public:
        ICG(Lexer* lex);
    private:
        Lexer* lexer;
        void handel_plus(){
            std::cout<<"++*ptr;"<<std::endl;
        };
        void handel_minus(){
            std::cout<<"--*ptr;"<<std::endl;
        };
        void handel_shift_left(){
            std::cout<<"--ptr;\n"<<std::endl;
        };
        void handel_shift_right(){
            std::cout<<"++ptr;"<<std::endl;
        };
        void handel_output(){
            std::cout<<"putchar(*ptr);"<<std::endl;
        };
        void handel_input(){
            std::cout<<"*ptr=getchar();"<<std::endl;
        };
        void handel_while(){
            std::cout<<"while (*ptr) {"<<std::endl;
        };
        void handel_end_while(){
            std::cout<<"}"<<std::endl;
        };
        void handel_eoi(){
            std::cout<<"end of file"<<std::endl;
        };

};



#endif