LIBS = -lsfml-window -lsfml-system -lsfml-graphics -lstdc++fs

# build an executable named windows from windows.c
all: nograv.o game.o spaceship.o header.o galaxy.o keyVector.o collisionHandler.o eventHandler.o bullet.o settings.o planetObj.o utility.o viewer.o drawable.o line.o planetView.o playground.o ground.o information.o
		g++ -g -Wall -o NoGravitar nograv.o game.o spaceship.o header.o galaxy.o keyVector.o collisionHandler.o eventHandler.o bullet.o settings.o planetObj.o utility.o viewer.o drawable.o line.o planetView.o playground.o ground.o information.o $(LIBS)

nograv.o: nograv.cpp
		g++ -c nograv.cpp $(LIBS)


#HANDLERS
collisionHandler.o: Handlers/collisionHandler.hpp Handlers/collisionHandler.cpp Classes/galaxy.hpp Classes/keyVector.hpp
		g++ -c Handlers/collisionHandler.cpp $(LIBS)

eventHandler.o: Handlers/eventHandler.hpp Handlers/eventHandler.cpp Classes/galaxy.hpp Classes/keyVector.hpp
		g++ -c Handlers/eventHandler.cpp $(LIBS)


#CLASSES
bullet.o: Classes/bullet.hpp Classes/bullet.cpp Classes/entity.hpp Classes/movable.hpp Classes/drawable.hpp Classes/settings.hpp
	g++ -c Classes/bullet.cpp $(LIBS)

drawable.o: Classes/drawable.hpp Classes/drawable.cpp Classes/drawable.tpp Classes/entity.hpp Classes/movable.hpp Classes/shape.hpp
	g++ -c Classes/drawable.cpp $(LIBS)

galaxy.o: Classes/galaxy.hpp Classes/galaxy.cpp Classes/spaceship.hpp Classes/planetObj.hpp Classes/planetView.hpp Classes/utility.hpp Classes/playground.hpp Classes/game.hpp Handlers/collisionHandler.hpp
	g++ -c Classes/galaxy.cpp $(LIBS)

game.o: Classes/game.hpp Classes/game.cpp Classes/galaxy.hpp Classes/keyVector.hpp Classes/header.hpp Handlers/eventHandler.hpp
		g++ -c Classes/game.cpp $(LIBS)

ground.o: Classes/ground.hpp Classes/ground.cpp Classes/entity.hpp Classes/shape.hpp Classes/drawable.hpp Classes/utility.hpp Classes/settings.hpp
		g++ -c Classes/ground.cpp $(LIBS)

header.o: Classes/header.hpp Classes/header.cpp Classes/viewer.hpp Classes/information.hpp
		g++ -c Classes/header.cpp $(LIBS)

information.o: Classes/information.hpp Classes/information.cpp
		g++ -c Classes/information.cpp $(LIBS)

keyVector.o: Classes/keyVector.hpp Classes/keyVector.cpp
		g++ -c Classes/keyVector.cpp $(LIBS)

line.o: Classes/line.hpp Classes/line.cpp
		g++ -c Classes/line.cpp $(LIBS)

planetObj.o: Classes/planetObj.hpp Classes/planetObj.cpp Classes/drawable.hpp Classes/planetView.hpp
		g++ -c Classes/planetObj.cpp $(LIBS)

planetView.o: Classes/planetView.hpp Classes/planetView.cpp Classes/playground.hpp Classes/spaceship.hpp
		g++ -c Classes/planetView.cpp $(LIBS)

playground.o: Classes/playground.hpp Classes/playground.cpp Classes/viewer.hpp
		g++ -c Classes/playground.cpp $(LIBS)

settings.o: Classes/settings.hpp Classes/settings.cpp
		g++ -c Classes/settings.cpp $(LIBS)

spaceship.o: Classes/spaceship.hpp Classes/spaceship.cpp Classes/bullet.hpp Classes/playground.hpp
		g++ -c Classes/spaceship.cpp $(LIBS)

utility.o: Classes/utility.hpp Classes/utility.cpp Classes/drawable.hpp
		g++ -c Classes/utility.cpp $(LIBS)

viewer.o: Classes/viewer.hpp Classes/viewer.cpp Classes/drawable.hpp
		g++ -c Classes/viewer.cpp $(LIBS)

#CLEANER
clean:
	  $(RM) *.o




#Your makefile should be like this:

test: test.o Classes/object_test.hpp
		g++ -g -Wall -o Test test.o $(LIBS)

test.o: test.cpp Classes/object_test.hpp
		g++ -c test.cpp $(LIBS)


#If you want you can write it in this Makefile
test2: test2.o ground.o drawable.o utility.o settings.o line.o bullet.o
		g++ -g -Wall -o Test test2.o ground.o drawable.o utility.o settings.o line.o bullet.o $(LIBS)

test2.o: test2.cpp Classes/ground.hpp
		g++ -c -Wall -pedantic -W test2.cpp $(LIBS)

bunker.o: Classes/bunker.hpp Classes/bunker.cpp
		g++ -c Classes/bunker.cpp $(LIBS)


test3: test3.o line.o
		g++ -g -Wall -o Test test3.o line.o $(LIBS)

test3.o: test3.cpp Classes/line.hpp
		g++ -c test3.cpp $(LIBS)
		#BASE

object_test.o: object_test.hpp object_test.cpp Classes/viewer.hpp
		g++ -c -c -Wall -pedantic -W object_test.cpp $(LIBS)

entity.o: Classes/entity.hpp Classes/entity.cpp
		g++ -c Classes/entity.cpp $(LIBS)
