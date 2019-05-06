#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

void testVillageCardEffect(){
	
	int card = 1; 
	struct gameState *state = malloc(sizeof(struct gameState));
	int handPos = 0;
	int currentPlayer = 0;	

	state->handCount[currentPlayer] = 5;
	state->deckCount[currentPlayer] = 10;
	state->numActions = 1;

	villageCardEffect(card, state, handPos, currentPlayer);

	if(state->handCount[currentPlayer] == 5){
		printf("villageCardEffect(): PASS when correct number of cards remain player's hand. Expected 5, actual %d\n", state->handCount[currentPlayer]);
	}
	else
		printf("villageCardEffect(): FAIL when correct number of cards remain player's hand. Expected 5, actual %d\n", state->handCount[currentPlayer]);
		//printf("villageCardEffect(): FAIL when correct number of cards remain player's hand.\n");
		
	if(state->numActions == 2){
		
		printf("villageCardEffect(): PASS when correct number of actions remain after being played. Expected 2, actual %d\n", state->numActions);
	}
	else
		printf("villageCardEffect(): FAIL when correct number of actions remain after being played. Expected 2, actual %d\n", state->numActions);
//		printf("villageCardEffect(): FAIL when correct number of actions remain after being played.\n");
}

int main(int argc, char *argv[]){
	testVillageCardEffect();
	
	return 0;
}
