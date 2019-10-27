LIBS = -lsfml-window -lsfml-system -lsfml-graphics

# build an executable named windows from windows.c
all: nograv.o spaceship.o header.o universe.o keyVector.o collisionHandler.o eventHandler.o bullet.o settings.o planetObj.o utility.o
		g++ -g -Wall -o NoGravitar nograv.o spaceship.o header.o universe.o keyVector.o collisionHandler.o eventHandler.o bullet.o settings.o planetObj.o utility.o $(LIBS)

nograv.o: nograv.cpp
		g++ -c nograv.cpp $(LIBS)


#HANDLERS
collisionHandler.o: Handlers/collisionHandler.hpp Handlers/collisionHandler.cpp Classes/universe.hpp
		g++ -c Handlers/collisionHandler.cpp $(LIBS)

eventHandler.o: Handlers/eventHandler.hpp Handlers/eventHandler.cpp Handlers/collisionHandler.hpp Classes/keyVector.hpp
		g++ -c Handlers/eventHandler.cpp $(LIBS)


#CLASSES
spaceship.o: Classes/spaceship.hpp Classes/spaceship.cpp Classes/bullet.hpp
		g++ -c Classes/spaceship.cpp $(LIBS)

header.o: Classes/header.hpp Classes/header.cpp
		g++ -c Classes/header.cpp $(LIBS)

universe.o: Classes/universe.hpp Classes/universe.cpp Classes/spaceship.hpp Classes/planetObj.hpp Classes/utility.hpp
		g++ -c Classes/universe.cpp $(LIBS)

keyVector.o: Classes/keyVector.hpp Classes/keyVector.cpp
		g++ -c Classes/keyVector.cpp $(LIBS)

bullet.o: Classes/bullet.hpp Classes/bullet.cpp Classes/entity.hpp Classes/entity.tpp Classes/movable.hpp Classes/movable.tpp
		g++ -c Classes/bullet.cpp $(LIBS)

settings.o: Classes/settings.hpp Classes/settings.cpp
		g++ -c Classes/settings.cpp $(LIBS)

planetObj.o: Classes/planetObj.hpp Classes/planetObj.cpp Classes/entity.hpp Classes/entity.tpp
		g++ -c Classes/planetObj.cpp $(LIBS)

utility.o: Classes/utility.hpp Classes/utility.cpp
		g++ -c Classes/utility.cpp $(LIBS)

#CLEANER
clean:
	  $(RM) *.o




#Your makefile should be like this:

test: test.o Classes/object_test.hpp
		g++ -g -Wall -o Test test.o $(LIBS)

test.o: test.cpp Classes/object_test.hpp
		g++ -c test.cpp $(LIBS)


#If you want you can write it in this Makefile
test2: test2.o
		g++ -g -Wall -o Test test2.o $(LIBS)

test2.o: test2.cpp Classes/entity.hpp Classes/entity.tpp object_test.hpp object_test.tpp
		g++ -c -Wall -pedantic -W test2.cpp $(LIBS)

bunker.o: Classes/bunker.hpp Classes/bunker.cpp
		g++ -c Classes/bunker.cpp $(LIBS)

		#BASE

object_test.o: object_test.hpp object_test.cpp Classes/entity.hpp
		g++ -c -c -Wall -pedantic -W object_test.cpp $(LIBS)

entity.o: Classes/entity.hpp Classes/entity.cpp
		g++ -c Classes/entity.cpp $(LIBS)
