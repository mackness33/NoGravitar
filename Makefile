LIBS = -lsfml-window -lsfml-system -lsfml-graphics -lstdc++fs

# build an executable named windows from windows.c
all: nograv.o game.o scene.o gameplay.o spaceship.o utility.o information.o header.o galaxy.o keyVector.o collisionHandler.o eventHandler.o bullet.o settings.o planetObj.o utility.o viewer.o drawable.o line.o planetView.o playground.o ground.o bunker.o shooter.o text.o plainText.o selectionLabel.o
		g++ -g -Wall -o NoGravitar nograv.o scene.o game.o gameplay.o utility.o information.o spaceship.o header.o galaxy.o keyVector.o collisionHandler.o eventHandler.o bullet.o settings.o planetObj.o viewer.o drawable.o line.o planetView.o playground.o ground.o bunker.o shooter.o text.o plainText.o selectionLabel.o $(LIBS)

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

bunker.o: Classes/bunker.hpp Classes/bunker.cpp Classes/entity.hpp Classes/movable.hpp Classes/drawable.hpp Classes/settings.hpp Classes/line.hpp Classes/utility.hpp
	g++ -c Classes/bunker.cpp $(LIBS)

drawable.o: Classes/drawable.hpp Classes/drawable.cpp Classes/drawable.tpp Classes/entity.hpp Classes/movable.hpp Classes/shape.hpp
	g++ -c Classes/drawable.cpp $(LIBS)

galaxy.o: Classes/galaxy.hpp Classes/galaxy.cpp Classes/spaceship.hpp Classes/planetObj.hpp Classes/planetView.hpp Classes/utility.hpp Classes/playground.hpp Classes/game.hpp Handlers/collisionHandler.hpp
	g++ -c Classes/galaxy.cpp $(LIBS)

game.o: Classes/game.hpp Classes/game.cpp Classes/galaxy.hpp Classes/keyVector.hpp Classes/header.hpp Handlers/eventHandler.hpp Classes/spaceship.hpp
		g++ -c Classes/game.cpp $(LIBS)

gameplay.o: Classes/gameplay.hpp Classes/gameplay.cpp Classes/galaxy.hpp Classes/keyVector.hpp Classes/header.hpp Handlers/eventHandler.hpp Classes/spaceship.hpp
		g++ -c Classes/gameplay.cpp $(LIBS)

ground.o: Classes/ground.hpp Classes/ground.cpp Classes/entity.hpp Classes/shape.hpp Classes/drawable.hpp Classes/utility.hpp Classes/settings.hpp
		g++ -c Classes/ground.cpp $(LIBS)

header.o: Classes/header.hpp Classes/header.cpp Classes/viewer.hpp Classes/information.hpp
		g++ -c Classes/header.cpp $(LIBS)

information.o: Classes/information.hpp Classes/information.cpp Classes/utility.hpp
		g++ -c Classes/information.cpp $(LIBS)

keyVector.o: Classes/keyVector.hpp Classes/keyVector.cpp
		g++ -c Classes/keyVector.cpp $(LIBS)

line.o: Classes/line.hpp Classes/line.cpp
		g++ -c Classes/line.cpp $(LIBS)

planetObj.o: Classes/planetObj.hpp Classes/planetObj.cpp Classes/drawable.hpp Classes/planetView.hpp
		g++ -c Classes/planetObj.cpp $(LIBS)

planetView.o: Classes/planetView.hpp Classes/planetView.cpp Classes/playground.hpp Classes/spaceship.hpp Classes/bunker.hpp Classes/ground.hpp Classes/line.hpp Classes/galaxy.hpp
		g++ -c Classes/planetView.cpp $(LIBS)

playground.o: Classes/playground.hpp Classes/playground.cpp Classes/viewer.hpp
		g++ -c Classes/playground.cpp $(LIBS)

plainText.o: Classes/plainText.hpp Classes/plainText.cpp Classes/text.hpp Classes/entity.hpp Classes/essence.hpp Classes/utility.hpp Classes/information.hpp
		g++ -c Classes/plainText.cpp $(LIBS)

scene.o: Classes/scene.hpp Classes/scene.cpp Classes/viewer.hpp Classes/playground.hpp
		g++ -c Classes/scene.cpp $(LIBS)

settings.o: Classes/settings.hpp Classes/settings.cpp
		g++ -c Classes/settings.cpp $(LIBS)

selectionLabel.o: Classes/selectionLabel.hpp Classes/selectionLabel.cpp Classes/plainText.hpp
		g++ -c Classes/selectionLabel.cpp $(LIBS)

shooter.o: Classes/shooter.hpp Classes/shooter.cpp Classes/bullet.hpp Classes/information.hpp
		g++ -c Classes/shooter.cpp $(LIBS)

spaceship.o: Classes/spaceship.hpp Classes/spaceship.cpp Classes/bullet.hpp Classes/playground.hpp
		g++ -c Classes/spaceship.cpp $(LIBS)

text.o: Classes/text.hpp Classes/text.cpp Classes/entity.hpp Classes/essence.hpp
		g++ -c Classes/text.cpp $(LIBS)

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
test2: test2.o ground.o drawable.o utility.o text.o
		g++ -g -Wall -o Test test2.o drawable.o utility.o text.o $(LIBS)

test2.o: test2.cpp Classes/ground.hpp
		g++ -c -Wall -pedantic -W test2.cpp $(LIBS)

#bunker.o: Classes/bunker.hpp Classes/bunker.cpp
#		g++ -c Classes/bunker.cpp $(LIBS)


test3: test3.o line.o
		g++ -g -Wall -o Test test3.o line.o $(LIBS)

test3.o: test3.cpp Classes/line.hpp
		g++ -c test3.cpp $(LIBS)
		#BASE

object_test.o: object_test.hpp object_test.cpp Classes/viewer.hpp
		g++ -c -c -Wall -pedantic -W object_test.cpp $(LIBS)

entity.o: Classes/entity.hpp Classes/entity.cpp
		g++ -c Classes/entity.cpp $(LIBS)
