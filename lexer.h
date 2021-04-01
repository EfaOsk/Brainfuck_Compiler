#ifndef LEXER_H
#define LEXER_H

#include "language.h"

class Lexer {
    public:
        Lexer(std::istream& s): stream(s) {}
        void get(Language::Token& token);
    private:
        std::istream& stream;
};

#endif