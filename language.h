#ifndef LANUGAGE_H
#define LANUGAGE_H

#include <map>

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
const std::map<char, Token> SymbolToToken = {
    {'<', Token::t_shift_left},
    {'>', Token::t_shift_right},
    {'+', Token::t_plus},
    {'-', Token::t_minus},
    {'.', Token::t_output},
    {',', Token::t_input},
    {'[', Token::t_while},
    {']', Token::t_end_while},
};
const std::map<Token, char> TokenToChar = {
    {Token::t_shift_left, '<'},
    {Token::t_shift_right, '>'},
    {Token::t_plus, '+'},
    {Token::t_minus, '-'},
    {Token::t_output, '.'},
    {Token::t_input, ','},
    {Token::t_while, '['},
    {Token::t_end_while, '\0'},
};

#endif