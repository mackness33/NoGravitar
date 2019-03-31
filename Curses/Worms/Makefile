LIBS = -lncurses

all : main.o helper.o worms.o			#dependencies
			gcc -g -Wall -o hola main.o helper.o worms.o $(LIBS)

main.o : main.c helper.h worms.h
			gcc -c main.c $(LIBS)

helper.o : helper.c helper.h worms.h
			gcc -c helper.c $(LIBS)

worms.o : worms.c helper.h worms.h
			gcc -c worms.c $(LIBS)

clean:
			$(RM) *.o
