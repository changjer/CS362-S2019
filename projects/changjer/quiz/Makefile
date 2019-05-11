CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc -c testme.c -g $(CFLAGS)

randomTest: testme.o
	gcc -o randomTest testme.c $(CFLAGS)

all: randomTest

clean:
	rm *.o randomTest *.gcno

