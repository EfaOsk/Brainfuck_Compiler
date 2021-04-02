#include "interpreter.h"
#include <fstream>
#include <iostream>

using namespace std;

Interpreter::Interpreter(Lexer* l){
    lexer=l;
    Token token;
    lexer->get(token);
    while (token != Token::t_eoi){
        cout<<token<<endl;
        switch(token) {
            case Token::t_plus:
                memory[pos]++;
                break;
            case Token::t_minus:
                memory[pos]--;
                break;
            case Token::t_input:
                memory[pos]= fgetc(stdin);
                break;
            case Token::t_output:
                cout<<memory[pos]; // TO DO get ASCII value
                break;
            case Token::t_shift_left:
                pos--;
                break;
            case Token::t_shift_right:
                pos++;
                break;
            case Token::t_while:
                break;
            case Token::t_end_while:
                break;
        }
        lexer->get(token);
    }
}