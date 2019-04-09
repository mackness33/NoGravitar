LIBS = -lsfml-window -lsfml-system -lsfml-graphics
# build an executable named windows from windows.c
all: nograv.o spaceship.hpp
		g++ -g -Wall -o NoGravitar nograv.o $(LIBS)

nograv.o: nograv.cpp spaceship.hpp
		g++ -c nograv.cpp $(LIBS)

spaceship.o: spaceship.cpp spaceship.hpp
		g++ -c spaceship.cpp $(LIBS)

clean:
	  $(RM) *.o
