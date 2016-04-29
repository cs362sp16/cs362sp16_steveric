
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
		int testSupply[treasure_map+1];
		for(int i=0;i<treasure_map;i++){testSupply[i] = rand()%11 + 1;}
		for(int i=0;i<treasure_map;i++){p->supplyCount[i] = testSupply[i];}	
			
		int x=isGameOver(p);
			
		if(x==0){passes++; }
		if(x==1){fails++; }
	
	}		
	printf("\n\n False Positive Test Complete: %d passes,  %d fails",passes,fails);
	tpass=tpass+passes; tfail=tfail+fails;
	passes = 0; fails = 0;	
	
	
	
	////Test for 0 province detection/////
	/////////////////////////////////
		
	for(int i=0; i<cases; i++){
		int testSupply[treasure_map+1];
		for(int i=0;i<treasure_map;i++){testSupply[i] = rand()%11 + 1;}
		for(int i=0;i<treasure_map;i++){p->supplyCount[i] = testSupply[i];}	
		
		int pcard = rand()%2;
		p->supplyCount[province] = pcard;
		
		int x=isGameOver(p);
			
		if((x==0&&pcard==1)||(x==1&&pcard==0)){passes++;}
		else{fails++;}
		
	}		
	printf("\n\n 0 province Test Complete: %d passes,  %d fails",passes,fails);
	tpass=tpass+passes; tfail=tfail+fails;
	passes = 0; fails = 0;
	
	
	
	////Test for three 0 detection/////
	/////////////////////////////////
		
	for(int i=0; i<cases; i++){
		for(int i=0;i<treasure_map;i++){p->supplyCount[i] = rand()%13;}
		p->supplyCount[province] = 1;
		
		int game0count=0;

		
		for(int i=0;i<treasure_map;i++){if(p->supplyCount[i] ==0){game0count++;}}
			
		
		
		int x=isGameOver(p);
		
		if((x==0&&game0count<3)||(x==1&&game0count>2)){
			passes++;
			//printf("\nPass x: %d count: %d  Supply: %d",x,game0count, treasure_map);
			//for(int i=0;i<treasure_map;i++){printf("%d ",p->supplyCount[i]);}
		}
		else{
			fails++;
			//printf("\nFail x: %d count: %d  Supply: %d",x,game0count, treasure_map);
			//for(int i=0;i<treasure_map;i++){printf("%d ",p->supplyCount[i]);}
		}
	}		
	printf("\n\n Three 0 Test Complete: %d passes,  %d fails\n\n",passes,fails);
	tpass=tpass+passes; tfail=tfail+fails;
	passes = 0; fails = 0;


	//result output
			printf("\n\n            Test Complete: %d total passes,  %d total fails\n\n\n",tpass,tfail);
	


return 0;
}

