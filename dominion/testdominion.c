//Playdom 2

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"
#include <assert.h>

#define MAX_TESTS 20

int main (int argc, char** argv) {

	
	
	// Seed system with input
	int seed = atoi(argv[1]);
	srand(seed);
	
	struct gameState G;
	struct gameState *p = &G;
	
	char string[20];

	
	
  
	for(int i=0; i<=MAX_TESTS-1; i++){
		
		printf ("Starting game # %d\n", i+1);
		
		// Random # Players
		int numPlayers = rand()%3+2;
		printf("players: %d \n", numPlayers);
		
		// Select Random Cards
		int k[10];
		int first = rand()%8 + 8;
		for (int j = 0; j < 10; j++){ k[j] = first+j; } 
		//Print Cards
		for (int j = 0; j < 10; j++) {
		cardNumToName(k[j], string);
		printf("card at position %d is %s\n", j, string);
		}
		
		
		int initGame = initializeGame(numPlayers, k, rand(), p);
		assert(initGame == 0);
		
		int treasure = 0;
		int buys = -1;
		int cheap = 99999;
		int v=0;int w=0;int x=0;int y=0;int z=0;
	
		for (z = 0; z < 10; z++) {
			if (cheap > getCost(k[z]))
			cheap = getCost(k[z]);
		}
		
		while (!isGameOver(p)) {


printf("\nCheck1:\n");

			for (y = 0; y < numHandCards(p); y++) {
				if ((handCard(y, p) != gold) && (handCard(y, p) != silver) && (handCard(y, p) != copper) && (handCard(y, p) != estate) && (handCard(y, p) != province)) {
					cardNumToName(handCard(y, p), string);
					printf("card: %s \n",string);
					playCard(y, -1, -1, -1, p);
					cardNumToName(handCard(y, p), string);
					break;
				}
			}
printf("\nCheck2:\n");
			treasure = 0;
			x = 0;
			
			//Treasure Count
	      	while (x < numHandCards(p)) {
				if (handCard(x, p) == copper){
					playCard(x, -1, -1, -1, p);
					treasure++;
				}
				else if (handCard(x, p) == silver){
					playCard(x, -1, -1, -1, p);
					treasure += 2;
				}
				else if (handCard(x, p) == gold){
					playCard(x, -1, -1, -1, p);
					treasure += 3;
				}
			x++;
			}
		
		
		    printf("Treasure: %d \n", treasure);

			buys = -1;
printf("\nCheck3:\n");
			if (treasure >= 8) {
				printf("province.\n\n");
				buyCard(province, p);
			}
			else if (treasure >= 6) {
				printf("gold.\n\n");
				buyCard(gold, p);
			}
			else if (treasure >= 3 && (rand()%2 == 0)) {
				printf("silver.\n\n");
				buyCard(silver, p);
			}
			else if (treasure < cheap) {
				printf("failure to buy \n");
				printf("\n");
			}

			else {
				while(buys == -1) {
					for (w = 0; w < 10; w++) {
						buys = buyCard(k[w], p);
						if (buys != -1) {
							break;
						}
					}
					break;
				}
			}
			
			
			printf("Next");
			
			endTurn(p);

		}
	
		
		printf ("Game Over\n\n");
		printf("Game number %d\n Score 1: Score 2: %d\n\n", i -1, scoreFor(0, p), scoreFor(1, p));
		printf("\n\n\n\n");
		
		
	}
	return 0;
}