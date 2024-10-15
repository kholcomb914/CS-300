FLAGS	= -g -c -Wall
LFLAGS	=
CC	= g++
OBJS	= main.o strategy.o factory.o event.o conference.o concert.o
SOURCE	= main.cpp strategy.cpp factory.cpp event.cpp conference.cpp concert.cpp
HEADER	= event.hpp conference.hpp concert.hpp
OUT	= a.out

all:	a.out

a.out: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

strategy.o: strategy.cpp
	$(CC) $(FLAGS) strategy.cpp

factory.o: factory.cpp
	$(CC) $(FLAGS) factory.cpp

event.o: event.cpp
	$(CC) $(FLAGS) event.cpp

conference.o: conference.cpp
	$(CC) $(FLAGS) conference.cpp

concert.o: concert.cpp
	$(CC) $(FLAGS) concert.cpp

clean:
	rm -f $(OBJS) $(OUT)

run: a.out
	./a.out
