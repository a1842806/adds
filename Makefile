main: Node.cpp LinkedList.cpp mainA-1.cpp
	rm -f main
	g++ Node.cpp LinkedList.cpp mainA-1.cpp -o main
	./main