demo: main.o screenSaver.o
	g++ main.o screenSaver.o -o demo
	
main.o: main.cpp screenSaver.h
	g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o app -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics.2.6.1 -lsfml-window.2.6.1 -lsfml-system.2.6.1

	
screenSaver.o: screenSaver.cpp screenSaver.h
	g++ screenSaver.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o app -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics.2.6.1 -lsfml-window.2.6.1 -lsfml-system.2.6.1

run: demo
	./demo
	./main
	
clean:
	rm -f *.o demo
