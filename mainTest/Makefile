CC=gcc
CFLAGS=-I.
DEPS = libs.h
OBJ = libs.o main.o 

%.o: %.c $(DEPS)
	$(CC) -g -O0 -c -o $@ $< $(CFLAGS)

tree: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o *.exe