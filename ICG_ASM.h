#ifndef ICG_ASM_H
#define ICG_ASM_H
#include <map>
#include "lexer.h"

class ICG_ASM{
    public:
        ICG_ASM(Lexer* lex, std::ofstream& s): stream(s) {
            lexer = lex;
            stream<<"add header";
            Token token;
            lexer->get(token);
            while (token!= Token::t_eoi)
            {
                switch (token)
                {
                case Token::t_shift_left:
                    handel_shift_left();
                    break;
                case Token::t_shift_right:
                    handel_shift_right();
                    break;
                case Token::t_plus:
                    handel_plus();
                    break;
                case Token::t_minus:
                    handel_minus();
                    break;
                case Token::t_input:
                    handel_input();
                    break;
                case Token::t_output:
                    handel_output();
                    break;
                case Token::t_while:
                    handel_while();
                    break;
                case Token::t_end_while:
                    handel_end_while();
                    break;
                }
                lexer->get(token);
            }
            stream<<"add ender";
        };
    private:
        Lexer* lexer;
        std::ofstream& stream;
        void handel_plus(){
            stream<<"add byte ptr [%%r8], 1"<<std::endl;
        };
        void handel_minus(){
            stream<<"sub byte ptr [%%r8], 1"<<std::endl;
        };
        void handel_shift_left(){
            stream<<"sub r8, 1"<<std::endl;
        };
        void handel_shift_right(){
            stream<<"add r8, 1"<<std::endl;
        };
        void handel_output(){
            stream<<"output"<<std::endl;
        };
        void handel_input(){
            stream<<"input"<<std::endl;
        };
        void handel_while(){
            stream<<"start while loop"<<std::endl;
        };
        void handel_end_while(){
            stream<<"end while loop"<<std::endl;
        };
        void handel_eoi(){
            stream<<"end of file"<<std::endl;
        };

};



#endif