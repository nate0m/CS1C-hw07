CC = g++

all: hw07

hw07: inventory.o hw07.cpp
	$(CC) hw07.cpp -o hw07 inventory.o

inventory.o: inventory.cpp inventory.h
	$(CC) -c inventory.cpp -o inventory.o

clean:
	rm hw07 *.o

tar:
	tar cf hw07.tar hw07.scr Makefile hw07.cpp inventory.cpp inventory.h inventory.txt
