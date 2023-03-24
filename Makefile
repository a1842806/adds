r1: r1.cpp main.cpp
	g++ r1.cpp main.cpp -o r1

main: main.cpp
	g++ -std=c++17 main.cpp -o main