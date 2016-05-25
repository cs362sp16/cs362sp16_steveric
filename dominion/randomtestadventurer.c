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


int main ( int argc, char *argv[] ){
	int seed = atoi(argv[1]);
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
		
		
		if(p->handCount[player] == 7){passes++;}
		

		
		printf("\ntick %d  numtres %d origdek %d \n",i,numOfTreasure,cardsInDeck);
		cardEffect(adventurer, 0,0,0, p, adventurerLocation, 0);
	
	}
	
	
		
			//result output
			printf("\n\n Test Complete: %d passes,  %d fails", passes, fails);
	

//*/
return 0;
}

