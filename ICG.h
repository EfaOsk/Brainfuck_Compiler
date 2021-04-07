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
            std::cout<<"plus"<<std::endl;
        };
        void handel_minus(){
            std::cout<<"minus"<<std::endl;
        };
        void handel_shift_left(){
            std::cout<<"shift left"<<std::endl;
        };
        void handel_shift_right(){
            std::cout<<"shift right"<<std::endl;
        };
        void handel_output(){
            std::cout<<"output"<<std::endl;
        };
        void handel_input(){
            std::cout<<"input"<<std::endl;
        };
        void handel_while(){
            std::cout<<"begin while loop"<<std::endl;
        };
        void handel_end_while(){
            std::cout<<"end while loop"<<std::endl;
        };
        void handel_eoi(){
            std::cout<<"end of file"<<std::endl;
        };

};



#endif