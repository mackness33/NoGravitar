LIBS = -lsfml-window -lsfml-system -lsfml-graphics
# build an executable named windows from windows.c
all: nograv.o Classes/spaceship.hpp Handlers/eventHandler.hpp
		g++ -g -Wall -o NoGravitar nograv.o $(LIBS)

nograv.o: nograv.cpp Classes/spaceship.hpp Handlers/eventHandler.hpp Classes/keyVector.hpp Handlers/transformationHandler.hpp Handlers/collisionHandler.hpp
		g++ -c nograv.cpp $(LIBS)

clean:
	  $(RM) *.o

#Your makefile should be like this:

#test: test.o Classes/object_test.hpp
#		g++ -g -Wall -o NoGravitar nograv.o $(LIBS)
#
#test.o: test.cpp Classes/object_test.hpp
#		g++ -c nograv.cpp $(LIBS)


#If you want you can write it in this Makefile
