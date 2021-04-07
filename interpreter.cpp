#include <iostream>
#include <fstream>
#include <stack>


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
    
    char memory[999]; // TODO: find default value? :D
    for (int i = 0; i<999;i++){
        memory[i]=0;
    }
    int pos=0;
    int open_brackets=0;
    char c= '\0';

    while (!file.eof()){
        switch(c) {
            case '+':
                memory[pos]++;
                break;
            case '-':
                memory[pos]--;
                break;
            case ',':
                memory[pos]= fgetc(stdin);
                break;
            case '.':
                cout<<(char)memory[pos];
                break;
            case '<':
                pos--;
                break;
            case '>':
                pos++;
                break;
            case '[':
                if (!memory[pos]){
                    open_brackets=1;
                    while (open_brackets>0){
                        file.get(c);
                        if (c=='['){
                            open_brackets++;
                        } else if (c== ']'){
                            open_brackets--;
                        }
                    }
                }
                break;
            case ']':
                if (memory[pos]){
                    open_brackets=1;
                    while (open_brackets>0){ 
                        file.seekg(-2, file.cur); 
                        file.get(c); 
                        if (c=='['){
                            open_brackets--;
                        } else if (c== ']'){
                            open_brackets++;
                        } 
                    }
                }
                break;
            default:
                break;
        }
        file.get(c);
    }
    file.close();
    return 0;
}