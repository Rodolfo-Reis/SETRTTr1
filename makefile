# Variables and rules
P=testapp
Objects= FIFO.o testapp.o
CFlags= -g -Wall -O3
CC = gcc

all: $(P)

# Generate app
$(P):$(Objects)
	$(CC) $(CFlags) -o $(P) $(Objects)

# Generate FIFO.o
FIFO.o: FIFO.c FIFO.h
	$(CC) $(CFlags) -c FIFO.c

# Generate testapp.o
testapp.o: testapp.c FIFO.h
	$(CC) $(CFlags) -c testapp.c

clean: 
	rm *.o $(P)

