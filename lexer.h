#ifndef LEXER_H
#define LEXER_H

#include "language.h"
#include <set>

class Lexer {
    public:
        Lexer(std::istream& s): stream(s) {}
        void get(Token& token){
            char c = '\0';
            std::set<char> valid_char= {'<', '>', '+', '-', '.', ',', '[', ']'};
            while ((!stream.eof())&&(c!= '+')&&(c!= '-')&&(c!= '<')&&(c!= '>')&&(c!= '.')&&(c!= ',')&&(c!= '[')&&(c!= ']')){
                stream.get(c);
            }
            if (stream.eof()){
                token = Token::t_eoi;
            } else {
                token = SymbolToToken.find(c)->second;
            }   
        }
        char c_peek() { return (char) stream.peek(); }

    private:
        std::istream& stream;
};

#endif