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


int main () {

	
	int passes = 0; int fails = 0; // keeps track of case results

	//initalize a fake gamestate
	struct gameState G;
	struct gameState *p = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  	initializeGame(2, k, 7, p);

	
	//The test
	int cases = 1000; //how many random numbers will be tested	
	for(int i=0; i<cases; i++){

		
		p->whoseTurn=rand()%4;
		int player = p->whoseTurn;
		
		int cardsInDeck = rand()%10;
		int cardsInHand = rand()%5+1;

		
		for(int i = 0 ; i<cardsInDeck; i++){p->deck[player][i] = rand()%27;}
		for(int i = 0 ; i<cardsInHand; i++){p->hand[player][i] = rand()%27;}
		
		
		
		p->deckCount[player] = cardsInDeck;
		
		int outpostLocation = rand()%cardsInHand;
		p->hand[player][outpostLocation]=outpost;
		p->handCount[player]=cardsInHand;
		
		cardEffect(outpost, 0,0,0, p, outpostLocation, 0);
		
		if(p->outpostPlayed){passes++;}
		else{fails++;}
	
	
	}
	
		
			//result output
			printf("\n\n Test Complete: %d passes,  %d fails",passes,fails);
	


return 0;
}

