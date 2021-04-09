#ifndef ICG_ASM_H
#define ICG_ASM_H
#include <map>
#include "lexer.h"
#include <stack>

class ICG_ASM{
    public:
        ICG_ASM(Lexer* lex, std::ofstream& s): stream(s) {
            lexer = lex;
            label_co=0;
            stream<<"global _start\n";
            stream<<"section .text\n";
            stream<<"out_put:\n  mov %rax, 1\n  mov %rdi, 1\n  mov %rsi, r8\n  mov %rdx, 1\n  syscall\n  ret\n";
            stream<<"in_put:\n  mov %rax, 0\n  mov %rdi, 0\n  mov %rsi, r8\n  mov %rdx, 1\n  syscall\n  ret\n";
            stream<<"_start:\n  mov r8, stack"<<std::endl;
            Token token;
            lexer->get(token);
            while (token!= Token::t_eoi)
            {
                switch (token)
                {
                case Token::t_shift_left:
                    handel_shift_left();
                    break;
                case Token::t_shift_right:
                    handel_shift_right();
                    break;
                case Token::t_plus:
                    handel_plus();
                    break;
                case Token::t_minus:
                    handel_minus();
                    break;
                case Token::t_input:
                    handel_input();
                    break;
                case Token::t_output:
                    handel_output();
                    break;
                case Token::t_while:
                    handel_while();
                    break;
                case Token::t_end_while:
                    handel_end_while();
                    break;
                }
                lexer->get(token);
            }
            stream<<"  mov eax,1  \n  int 0x80\n";
            stream<<"section .bss\n";
        };
    private:
        Lexer* lexer;
        std::ofstream& stream;
        std::stack<int> labels;
        int label_co;
        void handel_plus(){
            stream<<"  add $1, (r8)"<<std::endl;
        };
        void handel_minus(){
            stream<<"  sub $1, (r8)"<<std::endl;
        };
        void handel_shift_left(){
            stream<<"  dec r8"<<std::endl;
        };
        void handel_shift_right(){
            stream<<"  inc r8"<<std::endl;
        };
        void handel_output(){
            stream<<"  call out_put"<<std::endl;
        };
        void handel_input(){
            stream<<"  call in_put"<<std::endl;
        };
        void handel_while(){
            labels.push(++label_co);
            stream<<"L"<<label_co<<":"<<std::endl;
        };
        void handel_end_while(){
            stream<<"  loop L"<<labels.top()<<std::endl;
            labels.pop();
        };
        void handel_eoi(){
            stream<<"  end of file"<<std::endl;
        };

};



#endif