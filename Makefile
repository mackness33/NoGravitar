LIBS = -lsfml-window -lsfml-system -lsfml-graphics
# build an executable named windows from windows.c
all: main.o
		g++ -g -Wall -o main_ex main.o $(LIBS)

windows.o: main.cpp
		g++ -c main.cpp $(LIBS)

clean:
	  $(RM) *.o
