CC = gcc
FLAGS = -Wall -g


all: isort txtfind

isort: main_isort.o isort.o
	$(CC) $(FLAGS) -o isort main_isort.o isort.o

main_isort.o: main_isort.c isort.h
	$(CC) $(FLAGS) -c main_isort.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

txtfind: main_txtfind.o txtfind.o
	$(CC) $(FLAGS) -o txtfind main_txtfind.o txtfind.o

main_txtfind.o: main_txtfind.c txtfind.h
	$(CC) $(FLAGS) -c main_txtfind.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c 

.PHONY: clean all

clean:
	rm -f *.o isort txtfind
