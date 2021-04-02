/*
T-403-FORC - Forritun í C++
Assignment 5
    BRAIN F**K COMPILER

author:
    Eva Ósk Gunnarsdóttir
        evag18@ru.is
*/

#include <iostream>
#include <fstream>
#include "lexer.h"
#include "interpreter.h"
#include "language.h"


using namespace std;

int main(int argc, char* argv[]){
    // ./main FILENAME

    // Get filename  from argv
    string filename = "tests/helloworld.txt";
    if ( argc >= 2) {
        filename = argv[1];
    }
    // Open file to compile
    ifstream file( filename );
    if ( !file.good() ) {
        cout << "Could not open input file '"<< filename << "'." << endl;
        return -1;
    }
    Lexer* lexer;
    lexer = new Lexer(file);
    Token token;
    lexer->get(token);
    Interpreter* interp;
    interp = new Interpreter(lexer);

    return 0;
}
