
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "interface.h"



int CardCons(gameState *pStart, gameState *pEnd){
	gameState *stateArray[2] = [pStart, pEnd];
	
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

	
		///// count cards in players HAND /////
		numPlayers = pStart->numPlayers;
		// start
		for(int i=0; i<numPlayers; i++){
			for(int j=0; j<pStart->handCount[i]; j++){
				stAr[pStart->hand[i][j]]++;
			}
		}
		//end
		for(int i=0; i<numPlayers; i++){
			for(int j=0; j<pEnd->handCount[i]; j++){
				stEnd[pEnd->hand[i][j]]++;
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
				stEnd[pEnd->deck[i][j]]++;
			}
		}
			

		if(stAr==enAr){return 1;}
		else{retrun 0;}

	}


