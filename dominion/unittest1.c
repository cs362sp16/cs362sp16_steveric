	
//isGameOver test
  
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

	
	int passes = 0; int fails = 0; // keeps track of case results 
	int tpass = 0;	int tfail = 0;// totals

	//initalize a fake gamestate
	struct gameState G;
	struct gameState *p = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  	initializeGame(2, k, 7, p);

	
	////Test for false positives/////
	/////////////////////////////////
	int cases = 1000; //how many random numbers will be tested	
	for(int i=0; i<cases; i++){
		
		int player = rand()%4;
		int random = rand()%(MAX_HAND);
		
		p->whoseTurn=player;
		p->handCount[player]=random;
		
		int answer = numHandCards(p);
		
		if(answer == random ){passes++;}
		else{
			fails++; 
			printf("\nFailure on player %d, returned: %d should be %d",player,answer,random);
		}
		
		
	}



	//result output
			printf("\n\n            Test Complete: %d total passes,  %d total fails\n\n\n",passes,fails);
	


return 0;
}

