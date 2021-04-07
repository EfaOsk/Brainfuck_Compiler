
interpereter: interpereter.o
	g++ -o interpereter interpereter.cpp -std=c++11

interpereter.o: interpereter.cpp
	c++ -c interpereter.cpp -std=c++11

compiler: main.o
	g++ -o compiler main.cpp -std=c++11

main.o: main.cpp language.h ICG.h lexer.h
	g++ -c main.cpp -std=c++11

clean:
	rm *.o compiler interpereter
