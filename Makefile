LIBS = -lsfml-window -lsfml-system -lsfml-graphics

# build an executable named windows from windows.c
all: nograv.o spaceship.o header.o universe.o keyVector.o collisionHandler.o eventHandler.o
		g++ -g -Wall -o NoGravitar nograv.o spaceship.o header.o universe.o keyVector.o collisionHandler.o eventHandler.o $(LIBS)

nograv.o: nograv.cpp Classes/header.hpp Classes/universe.hpp Handlers/eventHandler.hpp Classes/keyVector.hpp
		g++ -c nograv.cpp $(LIBS)


#CLASSES
spaceship.o: Classes/spaceship.hpp Classes/spaceship.cpp
		g++ -c Classes/spaceship.cpp $(LIBS)

header.o: Classes/header.hpp Classes/header.cpp
		g++ -c Classes/header.cpp $(LIBS)

universe.o: Classes/universe.hpp Classes/universe.cpp
		g++ -c Classes/universe.cpp $(LIBS)

keyVector.o: Classes/keyVector.hpp Classes/keyVector.cpp
		g++ -c Classes/keyVector.cpp $(LIBS)

#HANDLERS
collisionHandler.o: Handlers/collisionHandler.hpp Handlers/collisionHandler.cpp Classes/spaceship.hpp
		g++ -c Handlers/collisionHandler.cpp $(LIBS)

eventHandler.o: Handlers/eventHandler.hpp Handlers/eventHandler.cpp Handlers/collisionHandler.hpp Classes/keyVector.hpp
		g++ -c Handlers/eventHandler.cpp $(LIBS)


#CLEANER
clean:
	  $(RM) *.o




#Your makefile should be like this:

test: test.o Classes/object_test.hpp
		g++ -g -Wall -o Test test.o $(LIBS)

test.o: test.cpp Classes/object_test.hpp
		g++ -c test.cpp $(LIBS)


#If you want you can write it in this Makefile
test2: test2.o bunker.o
		g++ -g -Wall -o Test test2.o bunker.o $(LIBS)

test2.o: test2.cpp Classes/bunker.hpp
		g++ -c test2.cpp $(LIBS)

bunker.o: Classes/bunker.hpp Classes/bunker.cpp
		g++ -c Classes/bunker.cpp $(LIBS)
