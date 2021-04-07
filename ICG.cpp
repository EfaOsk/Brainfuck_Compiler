#include <iostream>
#include <fstream>
#include "lexer.h"
#include "ICG.h"

using namespace std;

ICG::ICG(Lexer* lex){
    lexer = lex;

    cout << "extern int putchar(int);"<<endl;
    cout << "extern char getchar();"<<endl;
    cout << "char array[30000];"<<endl;
    cout << "char *ptr = &array[0];"<<endl;
    cout << "int main () {"<<endl;

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
    cout<< "}"<<endl;
    
}
