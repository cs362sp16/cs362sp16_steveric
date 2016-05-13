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

	
	srand(7);
	
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

		//int situation = (rand()%3)+1;
		
		
		int player = 0;
		int cardsInDeck = rand()%20+6;
		int cardsInHand = (rand()%5)+3;
		
		for(int i = 0 ; i<cardsInDeck; i++){p->deck[player][i] = (rand()%20)+7;}
		for(int i = 0 ; i<cardsInHand; i++){p->hand[player][i] = (rand()%20)+7;}
		
		p->deckCount[player] = cardsInDeck;
		
		p->handCount[player]=cardsInHand;
		
		int numOfTreasure = (rand()%(cardsInDeck+cardsInHand)+2);
		for(int i=0; i<numOfTreasure; i++){

			int deckOrHand = rand()%2;
			//int treasureType = (rand()%3)+4;
			int deckLoc=rand()%cardsInDeck;
			int handLoc=rand()%cardsInHand;
			int wasup;
			if(deckOrHand){p->hand[player][handLoc]=gold;}
			else{p->deck[player][deckLoc]=gold;}		
		}
		
		
		int secondTreasure;
		
		/*for(int i=0; i<cardsInDeck;i++){
			int count = 0;
			if(p->hand[player][i]==gold;)
			{
				count++;
				if(count==2){secondTreasure=i;}
			}
		}*/
		
		
		
		int adventurerLocation = rand()%cardsInHand;
		p->hand[player][adventurerLocation]=adventurer;
		
		
		if(cardsInHand==p->handCount){passes++;}
		

		
		
		cardEffect(adventurer, 0,0,0, p, adventurerLocation, 0);
	
	}
	
	
		
			//result output
			printf("\n\n Test Complete: %d passes,  %d fails", passes, fails);
	

//*/
return 0;
}

