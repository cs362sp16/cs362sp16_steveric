/* This is a unit test for the whoseTurn() functions
 *	sets a value to whoesturn in the gameState 
 *	then compares it to the return of the function
 *	whoseTurn(). this test does not fail invalid 
 *	number of players because the function does not 
 *	specify that it is supposed to do so.
 *
 */
  
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main (){

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
		
		int hallLocation = rand()%cardsInHand;
		p->hand[player][hallLocation]=great_hall;
		p->handCount[player]=cardsInHand;
		
		
		int handBefore, handAfter, deckBefore, deckAfter, actionsBefore, actionsAfter;
		
		handBefore = p->handCount[player];
		deckBefore = p->deckCount[player];
		actionsBefore = p->numActions;
		
		cardEffect(great_hall, 0,0,0, p, hallLocation, 0);
		
		handAfter = p->handCount[player];
		deckAfter = p->deckCount[player];	
		actionsAfter = p->numActions;
		
		
		if((handAfter==handBefore) && (deckBefore == deckAfter + 1) && (actionsAfter == actionsBefore+1)){passes++;}
		else if((deckAfter == 0) && (handAfter == handBefore + deckBefore -1)&&(actionsAfter == actionsBefore+1)){passes++;}
		else{
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

