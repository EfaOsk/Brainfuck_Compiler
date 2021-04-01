#ifndef LANUGAGE_H
#define LANUGAGE_H

#include <map>

class Language {
public:
    enum Token {
        t_shift_left = 256, // <
        t_shift_right,      // >
        t_plus,             // +
        t_minus,            // -
        t_output,           // .
        t_input,            // ,
        t_while,            // [
        t_end_while,        // ]
        t_eoi,              // End of input.
        t_unknown           // unknown token.
    };
    static const std::map<char,Token> SymbolToToken;
    static std::map<Token,char> TokenToText;
    static void init() {
        populate_token_to_text();
    }

private:
    static void populate_token_to_text();
};

#endif