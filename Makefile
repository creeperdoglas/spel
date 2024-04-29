FLAGS=-std=c++17 -Wall -Wextra -pedantic -Weffc++ -Woverloaded-virtual -fmax-errors=3 -g
LIBS=-I/usr/include/SFML/ -lsfml-window -lsfml-graphics -lsfml-system
OBJS=main.o

game: $(OBJS)
	g++ $(FLAGS) -o $@ $^ $(LIBS)

%.o: %.cc %.h
	g++ $(FLAGS) -c $<

main.o: main.cc
	g++ -c main.cc


.PHONY: clean
clean:
	rm *.o game
