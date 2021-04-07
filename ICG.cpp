#include <iostream>
#include <fstream>
#include "lexer.h"
#include "ICG.h"

using namespace std;

ICG::ICG(Lexer* lex){
    lexer = lex;
    Token token;
    lexer->get(token);
    while (token!= Token::t_eoi)
    {
        cout<<token<<endl;
        lexer->get(token);
    }
    
}