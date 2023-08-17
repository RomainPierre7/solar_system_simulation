OBJ = src/main.o src/planet.o

all: app

%.o: %.cpp
	g++ -c $< -o $@

app: $(OBJ)
	g++ $(OBJ) -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f src/*.o