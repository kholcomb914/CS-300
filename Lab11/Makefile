OBJS	= main.o vigenere.o
SOURCE	= main.cpp vigenere.cpp
HEADER	= vigenere.h
OUT	= main
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	main

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

vigenere.o: vigenere.cpp
	$(CC) $(FLAGS) vigenere.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUT)

run: main
	./main

