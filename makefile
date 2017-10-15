all: functions.o main.o
	gcc -o list functions.o main.o

functions.o: functions.c functions.h
	gcc -c functions.c

main.o: main.c functions.h
	gcc -c main.c

run: all
	./list

clean: 
	rm *.o
	rm *~
