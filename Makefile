LIBS = -lsfml-window -lsfml-system -lsfml-graphics -lstdc++fs

# build an executable named windows from windows.c
all: nograv.o game.o scene.o gameplay.o spaceship.o utility.o information.o header.o galaxy.o keyVector.o collisionHandler.o eventHandler.o bullet.o planetObj.o utility.o viewer.o drawable.o line.o planetView.o playground.o ground.o bunker.o shooter.o text.o label.o selectionLabel.o startView.o menu.o living.o points.o tractorBeam.o fuel.o fuelLabel.o
		g++ -g -Wall -o NoGravitar nograv.o scene.o game.o gameplay.o utility.o information.o spaceship.o header.o galaxy.o keyVector.o collisionHandler.o eventHandler.o bullet.o  planetObj.o viewer.o drawable.o line.o planetView.o playground.o ground.o bunker.o shooter.o text.o label.o selectionLabel.o startView.o menu.o living.o points.o tractorBeam.o fuel.o fuelLabel.o $(LIBS)

nograv.o: nograv.cpp
		g++ -c nograv.cpp $(LIBS)


#HANDLERS
collisionHandler.o: Handlers/collisionHandler.hpp Handlers/collisionHandler.cpp Classes/galaxy.hpp Classes/keyVector.hpp
		g++ -c Handlers/collisionHandler.cpp $(LIBS)

eventHandler.o: Handlers/eventHandler.hpp Handlers/eventHandler.cpp Classes/galaxy.hpp Classes/keyVector.hpp
		g++ -c Handlers/eventHandler.cpp $(LIBS)


#CLASSES
bullet.o: Classes/bullet.hpp Classes/bullet.cpp Classes/entity.hpp Classes/movable.hpp Classes/drawable.hpp
	g++ -c Classes/bullet.cpp $(LIBS)

bunker.o: Classes/bunker.hpp Classes/bunker.cpp Classes/entity.hpp Classes/movable.hpp Classes/drawable.hpp Classes/line.hpp Classes/utility.hpp Classes/shooter.hpp
	g++ -c Classes/bunker.cpp $(LIBS)

drawable.o: Classes/drawable.hpp Classes/drawable.cpp Classes/drawable.tpp Classes/entity.hpp Classes/movable.hpp Classes/shape.hpp
	g++ -c Classes/drawable.cpp $(LIBS)

galaxy.o: Classes/galaxy.hpp Classes/galaxy.cpp Classes/spaceship.hpp Classes/planetObj.hpp Classes/planetView.hpp Classes/utility.hpp Classes/playground.hpp Classes/game.hpp Handlers/collisionHandler.hpp
	g++ -c Classes/galaxy.cpp $(LIBS)

game.o: Classes/game.hpp Classes/game.cpp Classes/menu.hpp Classes/gameplay.hpp
		g++ -c Classes/game.cpp $(LIBS)

fuel.o: Classes/fuel.hpp Classes/fuel.cpp Classes/drawable.hpp Classes/entity.hpp Classes/essence.hpp
		g++ -c Classes/fuel.cpp $(LIBS)

fuelLabel.o: Classes/fuelLabel.hpp Classes/fuelLabel.cpp Classes/label.hpp Classes/drawable.hpp Classes/entity.hpp Classes/essence.hpp
		g++ -c Classes/fuelLabel.cpp $(LIBS)

gameplay.o: Classes/gameplay.hpp Classes/gameplay.cpp Classes/galaxy.hpp Classes/keyVector.hpp Classes/header.hpp Handlers/eventHandler.hpp Classes/spaceship.hpp Classes/spaceship.hpp Classes/scene.hpp
		g++ -c Classes/gameplay.cpp $(LIBS)

ground.o: Classes/ground.hpp Classes/ground.cpp Classes/entity.hpp Classes/shape.hpp Classes/drawable.hpp Classes/utility.hpp 
		g++ -c Classes/ground.cpp $(LIBS)

header.o: Classes/header.hpp Classes/header.cpp Classes/viewer.hpp Classes/information.hpp Classes/label.hpp Classes/points.hpp
		g++ -c Classes/header.cpp $(LIBS)

information.o: Classes/information.hpp Classes/information.cpp Classes/utility.hpp
		g++ -c Classes/information.cpp $(LIBS)

keyVector.o: Classes/keyVector.hpp Classes/keyVector.cpp
		g++ -c Classes/keyVector.cpp $(LIBS)

line.o: Classes/line.hpp Classes/line.cpp
		g++ -c Classes/line.cpp $(LIBS)

living.o: Classes/living.hpp Classes/living.cpp
		g++ -c Classes/living.cpp $(LIBS)

menu.o: Classes/menu.hpp Classes/menu.cpp Classes/scene.hpp
		g++ -c Classes/menu.cpp $(LIBS)

planetObj.o: Classes/planetObj.hpp Classes/planetObj.cpp Classes/drawable.hpp Classes/planetView.hpp
		g++ -c Classes/planetObj.cpp $(LIBS)

planetView.o: Classes/planetView.hpp Classes/planetView.cpp Classes/playground.hpp Classes/spaceship.hpp Classes/bunker.hpp Classes/ground.hpp Classes/line.hpp Classes/galaxy.hpp
		g++ -c Classes/planetView.cpp $(LIBS)

playground.o: Classes/playground.hpp Classes/playground.cpp Classes/viewer.hpp
		g++ -c Classes/playground.cpp $(LIBS)

label.o: Classes/label.hpp Classes/label.cpp Classes/text.hpp Classes/entity.hpp Classes/essence.hpp Classes/utility.hpp Classes/information.hpp
		g++ -c Classes/label.cpp $(LIBS)

points.o: Classes/points.hpp Classes/points.cpp Classes/label.hpp
		g++ -c Classes/points.cpp $(LIBS)

scene.o: Classes/scene.hpp Classes/scene.cpp Classes/viewer.hpp Classes/playground.hpp
		g++ -c Classes/scene.cpp $(LIBS)

selectionLabel.o: Classes/selectionLabel.hpp Classes/selectionLabel.cpp Classes/label.hpp
		g++ -c Classes/selectionLabel.cpp $(LIBS)

startView.o: Classes/startView.hpp Classes/startView.cpp Classes/selectionLabel.hpp Classes/viewer.hpp
		g++ -c Classes/startView.cpp $(LIBS)

shooter.o: Classes/shooter.hpp Classes/shooter.cpp Classes/bullet.hpp Classes/information.hpp
		g++ -c Classes/shooter.cpp $(LIBS)

spaceship.o: Classes/spaceship.hpp Classes/spaceship.cpp Classes/bullet.hpp Classes/playground.hpp Classes/living.hpp Classes/shooter.hpp Classes/tractorBeam.hpp
		g++ -c Classes/spaceship.cpp $(LIBS)

text.o: Classes/text.hpp Classes/text.cpp Classes/entity.hpp Classes/essence.hpp
		g++ -c Classes/text.cpp $(LIBS)

tractorBeam.o: Classes/tractorBeam.hpp Classes/tractorBeam.cpp Classes/shape.hpp Classes/essence.hpp
		g++ -c Classes/tractorBeam.cpp $(LIBS)

utility.o: Classes/utility.hpp Classes/utility.cpp Classes/drawable.hpp
		g++ -c Classes/utility.cpp $(LIBS)

viewer.o: Classes/viewer.hpp Classes/viewer.cpp Classes/drawable.hpp
		g++ -c Classes/viewer.cpp $(LIBS)

#CLEANER
clean:
	  $(RM) *.o
