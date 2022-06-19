# nazwa_operacji: zależności
#		komendy w bashu

all: main.exe

a.o: a.c
	gcc -c a.c

e.o: e.c
	gcc -c e.c

main.o: main.c include/a.h include/e.h
	gcc -c main.c

main.exe: main.o e.o a.o
	gcc main.o e.o a.o -o main.exe
