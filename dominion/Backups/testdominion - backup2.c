//Playdom 2

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"
#include <assert.h>


#define MAX_TESTS 1


int CardCons(struct gameState *pStart, struct gameState *pEnd);



int main (int argc, char** argv) {

	
	
	// Seed system with input
	int seed = atoi(argv[1]);
	srand(seed);
	
	struct gameState G;
	struct gameState *p = &G;
	
	struct gameState F;
	struct gameState *startState = &F;
	
	struct gameState T;
	struct gameState *tempState = &T;
	
	
	char string[20];

	
	
  
	for(int i=0; i<=MAX_TESTS-1; i++){
		
		printf ("Starting game # %d\n", i+1);
		
		// Random # Players
		int numPlayers = rand()%3+2;
		//printf("players: %d \n", numPlayers);
		
		// Select Random Cards
		int k[10];
		int first = rand()%8 + 8;
		for (int j = 0; j < 10; j++){ k[j] = first+j; } 
		//Print Cards
		for (int j = 0; j < 10; j++) {
		cardNumToName(k[j], string);
		//printf("card at position %d is %s\n", j, string);
		}
		
		
		int initGame = initializeGame(numPlayers, k, rand(), p);
		assert(initGame == 0);
		
		
		F = G;
		
		printf("\n\n Initalization Test:\n");
		CardCons(p,startState);
		
		
		
		int treasure = 0;
		int buys = -1;
		int cheap = 99999;
		int v=0;int w=0;int x=0;int y=0;int z=0;
	
		for (z = 0; z < 10; z++) {
			if (cheap > getCost(k[z]))
			cheap = getCost(k[z]);
		}
		
		while (!isGameOver(p)) {


//printf("\nCheck1:\n");
	T=G;
			for (y = 0; y < numHandCards(p); y++) {
				if ((handCard(y, p) != gold) && (handCard(y, p) != silver) && (handCard(y, p) != copper) && (handCard(y, p) != estate) && (handCard(y, p) != province)) {
					cardNumToName(handCard(y, p), string);
				//	printf("card: %s \n",string);
					playCard(y, -1, -1, -1, p);
					cardNumToName(handCard(y, p), string);
					break;
				}
			}
		//printf("\n\n Temp 1 Test:\n");
		if(CardCons(p,tempState)){;}
		else{return 1;}
//printf("\nCheck2:\n");
			treasure = 0;
			x = 0;
		T=G;	
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
		printf("\n\n Temp 2 Test:\n");
		if(CardCons(p,tempState)){;}
		else{return 1;}
		
	//	    printf("Treasure: %d \n", treasure);

			buys = -1;
//printf("\nCheck3:\n");
	T=G;
			if (treasure >= 8) {
	//			printf("province.\n\n");
				buyCard(province, p);
			}
			else if (treasure >= 6) {
	//			printf("gold.\n\n");
				buyCard(gold, p);
			}
			else if (treasure >= 3 && (rand()%2 == 0)) {
	//			printf("silver.\n\n");
				buyCard(silver, p);
			}
			else if (treasure < cheap) {
		//		printf("failure to buy \n");
		//		printf("\n");
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
			//printf("\n\n Temp 3 Test:\n");
		CardCons(p,tempState);		
			
			//printf("Next");
			
			endTurn(p);


		}

				
	int xx = sizeof(p->supplyCount);
	//printf("\n\n FUUUUUUUUUK: %d \n\n\n",xx);
		
		//printf ("Game Over\n\n");
		//printf("Game number %d\n Score 1: %d Score 2: %d\n\n", i -1, scoreFor(0, p), scoreFor(1, p));
		//printf("\n\n\n\n");
		

	}
	return 20;
}




/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
int CardCons(struct gameState *pStart, struct gameState *pEnd){
	
	
	int stAr[27]={0};
	int enAr[27]={0};
		

		////// Move supply cards to integer arrays /////
		for(int i=0; i<27; i++ ){
			//start
			if(pStart->supplyCount[i]>0){stAr[i]=pStart->supplyCount[i];}
			else{stAr[i]=0;}
			//end
			if(pEnd->supplyCount[i]>0){enAr[i]=pEnd->supplyCount[i];}
			else{enAr[i]=0;}
		}

	//*
		///// count cards in players HAND /////
		int numPlayers = pStart->numPlayers;
		// start
		for(int i=0; i<numPlayers; i++){
			for(int j=0; j<pStart->handCount[i]; j++){
				stAr[pStart->hand[i][j]]++;
			}
		}
		//end
		for(int i=0; i<numPlayers; i++){
			for(int j=0; j<pEnd->handCount[i]; j++){
				enAr[pEnd->hand[i][j]]++;
			}
		}
		
	
		///// count cards in DECK ///// 
		numPlayers = pStart->numPlayers;
		// start
		for(int i=0; i<numPlayers; i++){
			for(int j=0; j<pStart->deckCount[i]; j++){
				stAr[pStart->deck[i][j]]++;
			}
		}
		//end
		for(int i=0; i<numPlayers; i++){
			for(int j=0; j<pEnd->deckCount[i]; j++){
				enAr[pEnd->deck[i][j]]++;
			}
		}
		
		/*/
		///PRITN ARRAY
		for(int i=0; i<27; i++){
		char *nameocard[10];
		cardNumToName(i, nameocard);			
		printf("\n %s:   %d    %d   ",nameocard,stAr[i],enAr[i]);
		}
		*/
		
		for(int i=0; i<27; i++){
			if(stAr[i]==enAr[i]);
			else{
				printf("Result: Fail \n\n");
				return 0;
			}
		}
		//
		printf(" Result: Pass \n\n");
		return 1;
	}


