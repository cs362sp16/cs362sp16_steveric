//KingdomCards test
  
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {

	
	int passes = 0; int fails = 0; // keeps track of case results

	
	//The test
	int cases = 1000; //how many random numbers will be tested	
	for(int i=0; i<cases; i++){	
	

		
		
		int testK[10];
		for(int i=0;i<10;i++){testK[i]=(rand()%19+7);}
	
		int* kings=kingdomCards((testK[0]),testK[1],testK[2],testK[3],testK[4],testK[5],testK[6],testK[7],testK[8],testK[9]);
	
		for(int i = 0; i<10;i++ ){
			if(testK[i]!=kings[i]){fails++; break;}
			else if(testK[i]==kings[i] && i==9){passes++;}
			
			
			//printf("\n   %d    %d   ", testK[i],kings[i]);
		}
		
		//printf("\n\n");
	}
	
	
		printf("\n\nPasses: %d   Fails: %d\n\n",passes,fails);


return 0;
}

