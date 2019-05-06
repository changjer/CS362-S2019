#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

void testCouncil_roomCardEffect(){
	
	int card = 1; 
	struct gameState *state = malloc(sizeof(struct gameState));
	int handPos = 0;
	int currentPlayer = 0;	

	state->handCount[currentPlayer] = 5;
	state->deckCount[currentPlayer] = 10;
	state->numBuys = 1;

	council_roomCardEffect(card, state, handPos, currentPlayer);
	
	if(state->handCount[currentPlayer] == 8){ //Starts with 5, gain 4 cards but discard 1 for a correct total of 8
		printf("council_roomCardEffect(): PASS when correct number of cards remain player's hand.\n");
	}
	else
		printf("council_roomCardEffect(): FAIL when correct number of cards remain player's hand.\n");
		
	if(state->numBuys == 2){ //Starts with 1, gain 1 additional buy for a correct total of 2
		
		printf("council_roomCardEffect(): PASS when correct number of buys remain after being played.\n");
	}
	else
		printf("council_roomCardEffect(): FAIL when correct number of buys remain after being played.\n");
}

int main(int argc, char *argv[]){
	testCouncil_roomCardEffect();
	
	return 0;
}
