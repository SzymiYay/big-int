CC = gcc
CFLAGS = -g -Wall
OBJECTS = src/main.o src/big_int.o

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o run $(OBJECTS)

debug:
	make
	gdb run

clean:
	rm -rf run
	rm -rf *.o