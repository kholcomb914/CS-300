OBJS	= main.o hamming.o
SOURCE	= main.cpp hamming.cpp
HEADER	= hamming.hpp
OUT	= main
FLAGS	= -g -c -std=c++14
LDFLAGS	=
CC	= g++

all:	main

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

hamming.o: hamming.cpp
	$(CC) $(FLAGS) hamming.cpp

clean:
	rm -f $(OBJS) $(OUT)

run: main
	./main
