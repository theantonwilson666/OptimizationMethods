all: lab

lab: zlp.o main.o
	g++ -g main.o ZLP.o -o lab

main.o: main.cpp
	g++ -c -g main.cpp

zlp.o: ZLP.cpp
	g++ -g -c ZLP.cpp

clean:
	rm -rf *.o lab
