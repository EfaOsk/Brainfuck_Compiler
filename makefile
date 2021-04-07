
compiler: main.o
	g++ -o compiler main.cpp -std=c++11

main.o: main.cpp language.h ICG.h lexer.h
	g++ -c main.cpp -std=c++11

clean:
	rm *.o compiler
