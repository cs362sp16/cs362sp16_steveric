CFLAGS = -Wall -fpic -coverage -lm
 

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -fprofile-arcs -ftest-coverage -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
playdom2: dominion.o interface.o playdom2.c
	gcc -o playdom2 playdom2.c -g dominion.o rngs.o interface.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

	
all: playdom player 

unittest4:
	gcc unittest4.c -o unittest4 -g dominion.o rngs.o interface.o $(CFLAGS)
	

coverage: 
	gcc -fprofile-arcs -ftest-coverage unittest1.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest1.c > unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage unittest2.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage unittest3.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage unittest4.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov unittest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest1.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest2.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest3.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	gcc -fprofile-arcs -ftest-coverage cardtest4.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a
	gcov cardtest4.c >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	
	cat unittest1.c.gcov >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out	
	cat cardtest3.c.gcov >> unittestresults.out
	cat cardtest4.c.gcov >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
random:playdom player


	gcc -fprofile-arcs -ftest-coverage randomtestcard1.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a 42
	gcov randomtestcard1.c > randomtestcard1.out
	
	gcc -fprofile-arcs -ftest-coverage randomtestcard2.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a 42
	gcov randomtestcard2.c > randomtestcard2.out
	
	gcc -fprofile-arcs -ftest-coverage randomtestadventurer.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a 42
	gcov randomtestadventurer.c > randomtestadventurer.out
	
	gcov -f -b dominion.c >> randomtestresults.out
	
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestadventurer.out
	
adven: playdom player 
	
	gcc randomtestadventurer.c -o randl -g  dominion.o rngs.o interface.o $(CFLAGS)
	
testdom: dominion.o player playdom
	gcc -fprofile-arcs -ftest-coverage testdominion.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./a 42
	gcov dominion.c >> tester.out

	
tarantula:
	make clean
	gcc tarantula.c -o tarantula
	./tarantula
	
	
diff: dominion.o player playdom
	gcc -fprofile-arcs -ftest-coverage testdominion.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	./a 42
	gcov -f -b dominion.c > diff.out
	gcc run.c -o run
	./run domin1 domin2 42
	
clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM *.exe *.gch  *.stackdump
