//Playdom 2

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"
#include <assert.h>
#include <math.h>

#define MAX_TESTS 1

int randomtestcard1(int seed);
int randomtestcard2(int seed);
int randomtestcardA (int seed);



int main (int argc, char** argv) {

	
	
	// Seed system with input
	int seed = atoi(argv[1]);
	srand(seed);
	
	printf("\n\n SEED: %d \n\n", seed );
	
	int picker=rand()%10;
		printf("\n\n Pick: %d \n\n", picker );
	
	if(picker<3){return randomtestcard2(seed);}
	else if(picker < 7){randomtestcardA( seed );}
	else{return randomtestcard1(seed);}

}


int randomtestcard1(int seed){

	srand(seed);

	
	int passes = 0; int fails = 0; // keeps track of case results

	//initalize a fake gamestate
	struct gameState G;
	struct gameState *p = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  	initializeGame(2, k, 7, p);

	
	//The test

		
		p->whoseTurn=rand()%4;
		int player = p->whoseTurn;
		
		int cardsInDeck = rand()%10;
		int cardsInHand = rand()%5+1;

		
		for(int i = 0 ; i<cardsInDeck; i++){p->deck[player][i] = rand()%27;}
		for(int i = 0 ; i<cardsInHand; i++){p->hand[player][i] = rand()%27;}
		
		
		
		p->deckCount[player] = cardsInDeck;
		
		int smithyLocation = rand()%cardsInHand;
		p->hand[player][smithyLocation]=smithy;
		p->handCount[player]=cardsInHand;
		
		
		int handBefore, handAfter, deckBefore, deckAfter;
		
		handBefore = p->handCount[player];
		deckBefore = p->deckCount[player];
		
		SmithyCard( p, player, smithyLocation);
		
		handAfter = p->handCount[player];
		deckAfter = p->deckCount[player];	
		
		if((handAfter==handBefore+2) && (deckBefore == deckAfter + 3)){printf("\npass");return 1;}
		else if(deckAfter == 0 && handAfter == handBefore + deckBefore -1){printf("\npass");return 1;}
		else{
			fails++;
			//printf("\nfail");
			return 0;
		}
	
	
	
	
		
			//result output
			//printf("\n\n Test Complete: %d passes,  %d fails",passes,fails);
	


return 0;
}





int randomtestcard2(int seed){

	srand(seed);

	//printf("made it to in main");
	
	int passes = 0; int fails = 0; // keeps track of case results
	
	
	
	//initalize a fake gamestate
	struct gameState G;
	struct gameState *p = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	

  	initializeGame(2, k, 7, p);

	//printf("made it past initalization");
	
	//The test
	int cases = 1000; //how many random numbers will be tested	
	for(int i=0; i<cases; i++){

		int player = 0;
		int cardsInDeck = rand()%10;
		int cardsInHand = rand()%5+1;

		
		for(int i = 0 ; i<cardsInDeck; i++){p->deck[player][i] = rand()%27;}
		for(int i = 0 ; i<cardsInHand; i++){p->hand[player][i] = rand()%27;}
		
		p->deckCount[player] = cardsInDeck;
		
		int villageLocation = rand()%cardsInHand;
		p->hand[player][villageLocation]=village;
		p->handCount[player]=cardsInHand;
		
		
		int handBefore, handAfter, deckBefore, deckAfter, actionsBefore, actionsAfter;
		
		handBefore = p->handCount[player];
		deckBefore = p->deckCount[player];
		actionsBefore = p->numActions;
		
		cardEffect(village, 0,0,0, p, villageLocation, 0);
		
		handAfter = p->handCount[player];
		deckAfter = p->deckCount[player];	
		actionsAfter = p->numActions;
		
		
		if((handAfter==handBefore) && (deckBefore == deckAfter + 1) && (actionsAfter == actionsBefore+2)){return 1;passes++;}
		else if((deckAfter == 0) && (handAfter == handBefore + deckBefore -1)&&(actionsAfter == actionsBefore+2)){return 1; passes++;}
		else{
			return 0;
			fails++;
		
			printf("\nFailure: test");
			printf("\nbefore call handCount = %d   ", handBefore);
			printf("deckCount = %d   \n",deckBefore);
			printf("actionCount = %d   \n",actionsBefore);
		
			printf("after call handCount = %d   ", handAfter);
			printf("deckCount = %d   \n", deckAfter);
			printf("actionCount = %d   \n",actionsAfter);
		}
	
	
	
	}
	
	
		
			//result output
			printf("\n\n Test Complete: %d passes,  %d fails",passes,fails);
	


return 0;
}






int randomtestcardA ( int seed ){

	srand(seed);
printf("\n%d\n",seed);

	
	int passes = 0; int fails = 0; // keeps track of case results

	//initalize a fake gamestate
	struct gameState G;
	struct gameState *p = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
		   
		   
  	initializeGame(2, k, 7, p);

	
	//The test
	int cases = 100; //how many random numbers will be tested	
	for(int i=0; i<cases; i++){

		
		
		
		int player = 0;
		int numOfTreasure = (rand()%3+2);
		int cardsInDeck = (rand()%10)+numOfTreasure; 
		int cardsInHand = 5;
		
		for(int i = 0 ; i<cardsInDeck; i++){p->deck[player][i] = (rand()%20)+7;}// ensures no cards in deck are treasure
		for(int i = 0 ; i<cardsInHand; i++){p->hand[player][i] = (rand()%27);}
		
		p->deckCount[player] = cardsInDeck;
		p->handCount[player]=cardsInHand;
		
		int secondGoldLoc;
		for(int i=0; i<numOfTreasure; i++){
			
			int deckLoc=rand()%(cardsInDeck/numOfTreasure)+(i-1)*(cardsInDeck/numOfTreasure);
			p->deck[player][deckLoc]=gold;
			
			if(i==2){secondGoldLoc=deckLoc;}		
		}
		

		int adventurerLocation = rand()%cardsInHand;
		p->hand[player][adventurerLocation]=adventurer;
		
		
		if(p->handCount[player] == 7){passes++; return 1;}
		

		
		printf("\ntick %d  numtres %d origdek %d \n",i,numOfTreasure,cardsInDeck);
		cardEffect(adventurer, 0,0,0, p, adventurerLocation, 0);
	
	}
	
	
		
			//result output
			printf("\n\n Test Complete: %d passes,  %d fails", passes, fails);
	

//*/
return 0;
}






