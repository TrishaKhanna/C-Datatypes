CC = clang
CFLAGS = -Wall -pedantic -std=c99

a1.o: a1.c a1.h
	clang -Wall -pedantic -std=c99 -c a1.c

clean:
	rm *.o a1