CC = gcc
CFLAGS = -g -Wall -ansi -pedantic


maze: table.o map.o main.o movement.o terminal.o
	$(CC) table.o map.o main.o movement.o terminal.o -o maze

test: table.o test.o map.o
	$(CC) table.o test.o map.o movement.o-o test

table.o: table.c
	$(CC) $(CFLAGS)  -c table.c

test.o: test.c
	$(CC) $(CFLAGS)  -c test.c

map.o: map.c
	$(CC) $(CFLAGS)  -c map.c

movement.o: movement.c
	$(CC) $(CFLAGS)  -c movement.c 

terminal.o: terminal.c
	$(CC) $(CFLAGS)  -c terminal.c 

clean:
	rm -f *.exe *o
