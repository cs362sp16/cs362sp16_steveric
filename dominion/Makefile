CFLAGS = -Wall -fpic -coverage -lm
 

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

	
all: playdom player coverage	
	
	
unittest1: unittest1.c
	gcc -fprofile-arcs -ftest-coverage unittest1.c -o unittest1  -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c
	gcc -fprofile-arcs -ftest-coverage unittest2.c -o unittest2 -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c
	gcc -fprofile-arcs -ftest-coverage unittest3.c -o unittest3 -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c
	gcc -fprofile-arcs -ftest-coverage unittest4.c -o unittest4 -g  dominion.o rngs.o interface.o $(CFLAGS)
cardtest1: cardtest1.c
	
	gcc -fprofile-arcs -ftest-coverage cardtest1.c -o cardtest1 -g  dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c
	gcc -fprofile-arcs -ftest-coverage cardtest2.c -o cardtest2 -g  dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c
	gcc -fprofile-arcs -ftest-coverage cardtest3.c -o cardtest3 -g  dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c
	gcc -fprofile-arcs -ftest-coverage cardtest4.c -o cardtest4  -g  dominion.o rngs.o interface.o $(CFLAGS)



coverage: 
	gcc -fprofile-arcs -ftest-coverage unittest1.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest1.c > unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage unittest2.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest2.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage unittest3.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest3.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage unittest4.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest4.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest1.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest1.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest2.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest2.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest3.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest3.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest4.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest4.c >> unittestresults.out
	
	cat unittest1.c.gcov >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out	
	cat cardtest3.c.gcov >> unittestresults.out
	cat cardtest4.c.gcov >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
