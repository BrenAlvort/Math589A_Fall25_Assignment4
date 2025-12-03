CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2
LDFLAGS = -shared
LIB = libfixed_point.so

all: $(LIB)

$(LIB): fixed_point.o
	$(CC) $(LDFLAGS) -o $(LIB) fixed_point.o -lm

fixed_point.o: fixed_point.c fixed_point.h
	$(CC) $(CFLAGS) -c fixed_point.c

clean:
	rm -f *.o *.so main
