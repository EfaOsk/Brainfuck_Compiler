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
#include "language.h"
#include "ICG.h"


using namespace std;

int main(int argc, char* argv[]){
    // ./main <File to compile> <compiled file>

    // Get filename  from argv
    string filename = "tests/helloworld.txt";
    string comp_filename = "helloworld.c";
    if ( argc >= 2) {
        filename = argv[1];
    }
    if ( argc >= 3) {
        comp_filename = argv[2];
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
    ofstream comp_file( comp_filename );
    ICG* icg;
    icg = new ICG(lexer, comp_file);
    file.close();
    comp_file.close();

    return 0;
}
