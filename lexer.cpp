#include "lexer.h"
#include "language.h"
#include <iostream>
#include <set>

using namespace std;

void Lexer::get(Language::Token& token){
    char c = '\0';
    set<char> valid_char= {'<', '>', '+', '-', '.', ',', '[', ']'};
    while ((valid_char.find(c)==valid_char.end) && (!stream.eof())){
        stream.get(c);
    }
    if (stream.eof()){
        token = Language::Token::t_eoi;
    } else {
        token = SymbolToToken[c];
    }
    
}
