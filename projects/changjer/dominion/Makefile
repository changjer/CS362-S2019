CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


#########

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4

unitTest1: dominion.o unittest1.c 
	gcc -o unitTest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unitTest2: dominion.o unittest2.c 
	gcc -o unitTest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unitTest3: dominion.o unittest3.c 
	gcc -o unitTest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unitTest4: dominion.o unittest4.c 
	gcc -o unitTest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

cardTest1: dominion.o cardtest1.c 
	gcc -o cardTest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardTest2: dominion.o cardtest2.c 
	gcc -o cardTest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardTest3: dominion.o cardtest3.c 
	gcc -o cardTest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

cardTest4: dominion.o cardtest4.c 
	gcc -o cardTest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c
	echo "Results for dominion tests: " > unittestresults.out
	echo " " >> unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unitTest1 dominion.c unittest1.c rngs.c $(CFLAGS)
	./unitTest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unitTest2 dominion.c unittest2.c rngs.c $(CFLAGS)
	./unitTest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unitTest3 dominion.c unittest3.c rngs.c $(CFLAGS)
	./unitTest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unitTest4 dominion.c unittest4.c rngs.c $(CFLAGS)
	./unitTest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardTest1 dominion.c cardtest1.c rngs.c $(CFLAGS)
	./cardTest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardTest2 dominion.c cardtest2.c rngs.c $(CFLAGS)
	./cardTest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardTest3 dominion.c cardtest3.c rngs.c $(CFLAGS)
	./cardTest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo " " >> unittestresults.out
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardTest4 dominion.c cardtest4.c rngs.c $(CFLAGS)
	./cardTest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe unitTest1 unitTest1.exe unitTest2 unitTest2.exe unitTest3 unitTest3.exe unitTest4 unitTest4.exe cardTest1 cardTest1.exe cardTest2 cardTest2.exe cardTest3 cardTest3.exe cardTest4 cardTest4.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
