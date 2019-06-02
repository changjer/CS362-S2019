#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

void testVillageCardEffect(int randomHandCount, int randomActionCount){
	
	int card = 1; 
	struct gameState *state = malloc(sizeof(struct gameState));
	int handPos = 0;
	int currentPlayer = 0;	
	int correctEndActionCount = randomActionCount++;

	state->handCount[currentPlayer] = randomHandCount;
	state->deckCount[currentPlayer] = 10;
	state->numActions = randomActionCount;

	villageCardEffect(card, state, handPos, currentPlayer);

	if(state->handCount[currentPlayer] == randomHandCount){
		printf("villageCardEffect(): PASS when correct number of cards remain player's hand. Expected %d, actual %d\n", randomHandCount, state->handCount[currentPlayer]);
	}
	else
		printf("villageCardEffect(): FAIL when correct number of cards remain player's hand. Expected %d, actual %d\n", randomHandCount,  state->handCount[currentPlayer]);
		
	if(state->numActions == correctEndActionCount){
		
		printf("villageCardEffect(): PASS when correct number of actions remain after being played. Expected %d, actual %d\n", correctEndActionCount, state->numActions);
	}
	else
		printf("villageCardEffect(): FAIL when correct number of actions remain after being played. Expected %d, actual %d\n", correctEndActionCount, state->numActions);
}

int main(int argc, char *argv[]){
	int handCountUpper = 20;
	int handCountLower = 3;
	int randomHandCount;
	int actionCountUpper = 100;
	int actionCountLower = 0;
	int randomActionCount;
	for(int i = 0; i < 50; i++){
		randomHandCount = (rand() % (handCountUpper - handCountLower + 1) + handCountLower);
		randomActionCount = (rand() % (actionCountUpper - actionCountLower + 1) + actionCountLower);
		testVillageCardEffect(randomHandCount, randomActionCount);
	}
	printf("Village card effect test complete\n");
		
	return 0;
}
