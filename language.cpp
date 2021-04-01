#include "language.h"

#include <iostream>

using namespace std;

const map<char, Language::Token> Language::SymbolToToken = {
    {'<', Token::t_shift_left},
    {'>', Token::t_shift_right},
    {'+', Token::t_plus},
    {'-', Token::t_minus},
    {'.', Token::t_output},
    {',', Token::t_input},
    {'[', Token::t_while},
    {']', Token::t_end_while},
};

map<Language::Token, char> Language::TokenToText;

void Language::populate_token_to_text()
{
    for ( auto& elem : Language::SymbolToToken ) {
        TokenToText[elem.second] = elem.first;
    }
    TokenToText[Token::t_eoi] = '\0';
    TokenToText[Token::t_unknown] = '?';
}
