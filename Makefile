LIBS = -lsfml-window -lsfml-system -lsfml-graphics
# build an executable named windows from windows.c
all: main.o spaceship.hpp
		g++ -g -Wall -o main_ex main.o $(LIBS)

main.o: main.cpp spaceship.hpp
		g++ -c main.cpp $(LIBS)

spaceship.o: spaceship.cpp spaceship.hpp
		g++ -c spaceship.cpp $(LIBS)

clean:
	  $(RM) *.o
