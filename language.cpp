#include "language.h"

#include <iostream>

using namespace std;

const map<char, Language::TokenName> Language::SymbolToTokenName = {
    {'<', TokenName::t_shift_left},
    {'>', TokenName::t_shift_right},
    {'+', TokenName::t_plus},
    {'-', TokenName::t_minus},
    {'.', TokenName::t_output},
    {',', TokenName::t_input},
    {'[', TokenName::t_while},
    {']', TokenName::t_end_while},
};

map<Language::TokenName, char> Language::TokenNameToText;

void Language::populate_tokenname_to_text()
{
    for ( auto& elem : Language::SymbolToTokenName ) {
        TokenNameToText[elem.second] = elem.first;
    }
    TokenNameToText[TokenName::t_eoi] = "<eoi>";
    TokenNameToText[TokenName::t_unknown] = "<unknown>";
}
