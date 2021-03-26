#ifndef LANUGAGE_H
#define LANUGAGE_H

#include <string>
#include <map>

class Language {
public:
    enum TokenName {
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
    static const std::map<std::char,TokenName> SymbolToTokenName;
    static std::map<TokenName,std::char> TokenNameToText;

private:
    static void populate_tokenname_to_text();
};

#endif