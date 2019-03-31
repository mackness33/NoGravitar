LIBS = -lsfml-window -lsfml-system
# build an executable named windows from windows.c
all: windows.o
		g++ -g -Wall -o window_ex windows.o $(LIBS)

windows.o: windows.cpp
		g++ -c windows.cpp $(LIBS)

clean:
	  $(RM) *.o
