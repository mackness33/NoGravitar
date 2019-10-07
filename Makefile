LIBS = -lsfml-window -lsfml-system -lsfml-graphics
# build an executable named windows from windows.c
all: nograv.o
		g++ -g -Wall -o NoGravitar nograv.o $(LIBS)

nograv.o: nograv.cpp Classes/spaceship.hpp Classes/header.hpp Classes/universe.hpp Handlers/eventHandler.hpp Classes/keyVector.hpp Handlers/collisionHandler.hpp
		g++ -c nograv.cpp $(LIBS)

clean:
	  $(RM) *.o

#Your makefile should be like this:

test: test.o Classes/object_test.hpp
		g++ -g -Wall -o Test test.o $(LIBS)

test.o: test.cpp Classes/object_test.hpp
		g++ -c test.cpp $(LIBS)


#If you want you can write it in this Makefile


test2: test2.o Classes/bunker.hpp
		g++ -g -Wall -o Test test2.o $(LIBS)

test2.o: test2.cpp Classes/bunker.hpp
		g++ -c test2.cpp $(LIBS)
