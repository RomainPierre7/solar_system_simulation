SRC = src/{main.cpp}

all: app

%.o: %.cpp
	g++ -c $< -o $@

app: src/main.o
	g++ src/main.o -o app -lsfml-graphics -lsfml-window -lsfml-system
	./app

clean:
	rm -f src/*.o