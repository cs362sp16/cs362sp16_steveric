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

unittest1: unittest1.c
	gcc -fprofile-arcs -ftest-coverage -o unittest1 unittest1.c  -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c
	gcc -fprofile-arcs -ftest-coverage -o unittest2 unittest2.c  -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c
	gcc -fprofile-arcs -ftest-coverage -o unittest3 unittest3.c  -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c
	gcc -fprofile-arcs -ftest-coverage -o unittest4 unittest4.c  -g  dominion.o rngs.o interface.o $(CFLAGS)
cardtest1: cardtest1.c
	
	gcc -fprofile-arcs -ftest-coverage -o cardtest1 cardtest1.c  -g  dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c
	gcc -fprofile-arcs -ftest-coverage -o cardtest2 cardtest2.c  -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

try: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 
	./unittest1
	./a
	gcov unittest1.c
	./unittest2
	./a
	gcov unittest2.c > a.txt
	./unittest3
	./a
	gcov unittest3.c
	./unittest4
	./a
	gcov unittest4.c
	./cardtest1
	./a
	gcov cardtest1.c
	./cardtest2
	gcov cardtest2.c
		
	a.out<<


clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
