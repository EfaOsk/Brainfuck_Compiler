#ifndef ICG_C_H
#define ICG_C_H
#include <map>
#include "lexer.h"

class ICG_C{
    public:
        ICG_C(Lexer* lex, std::ofstream& s): stream(s) {
            lexer = lex;

            stream << "extern int putchar(int);"<<std::endl;
            stream << "extern char getchar();"<<std::endl;
            stream << "char array[30000];"<<std::endl;
            stream << "char *ptr = &array[0];"<<std::endl;
            stream << "int main () {"<<std::endl;

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
            stream<< "}"<<std::endl;
        };
    private:
        Lexer* lexer;
        std::ofstream& stream;
        void handel_plus(){
            stream<<"++*ptr;"<<std::endl;
        };
        void handel_minus(){
            stream<<"--*ptr;"<<std::endl;
        };
        void handel_shift_left(){
            stream<<"--ptr;"<<std::endl;
        };
        void handel_shift_right(){
            stream<<"++ptr;"<<std::endl;
        };
        void handel_output(){
            stream<<"putchar(*ptr);"<<std::endl;
        };
        void handel_input(){
            stream<<"*ptr=getchar();"<<std::endl;
        };
        void handel_while(){
            if (lexer->c_peek()=='-'){
                Token token;
                lexer->get(token);
                if (lexer->c_peek()==']'){
                    lexer->get(token);
                    stream<<"*ptr=0;"<<std::endl;
                } else {
                    stream<<"while (*ptr) {"<<std::endl;
                    handel_minus();
                }

            } else {
                stream<<"while (*ptr) {"<<std::endl;
            }
            
        };
        void handel_end_while(){
            stream<<"}"<<std::endl;
        };
        void handel_eoi(){
            stream<<"end of file"<<std::endl;
        };

};



#endif