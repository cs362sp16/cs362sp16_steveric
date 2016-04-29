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

int values[27]={0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};

	
	int passes = 0; int fails = 0; // keeps track of case results

	
	//The test
	int cases = 1000; //how many random numbers will be tested	
	for(int i=0; i<cases; i++){	
	
		int x = (rand()%36)-5;
		
		
		int cost = getCost(x);
		
		if((x>=0)&&(x<=26)){
			int test =values[x];
			if(cost==test){passes++;}
			else{fails++;}
		}
		else if((x<0)||(x>26)){
			if(cost==-1){passes++;}
			else{fails++; printf("returned %d  given %d\n",cost, x);}
		}
		
	}
	
	printf("Passes %d  Fails %d",passes, fails);

return 0;
}

