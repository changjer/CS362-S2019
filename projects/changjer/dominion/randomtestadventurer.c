#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

void testAdventurerCardEffect(int randomHandCount){
	
	int card = 1; 
	struct gameState *state = malloc(sizeof(struct gameState));
	int currentPlayer = 0;	
	int drawntreasure = 0;
	int cardDrawn = -1;
	int temphand[100];
	int z = 0;
	int correctHandCount;

	state->handCount[currentPlayer] = randomHandCount;
	state->hand[currentPlayer][0] = 1;
	state->hand[currentPlayer][2] = 1;
	state->hand[currentPlayer][3] = 1;
	state->hand[currentPlayer][4] = 1;
	state->hand[currentPlayer][5] = 1;
	

	state->deckCount[currentPlayer] = 10;
	state->deck[currentPlayer][0] = copper;
	state->deck[currentPlayer][1] = estate;
	state->deck[currentPlayer][2] = copper;
	state->deck[currentPlayer][3] = estate;
	state->deck[currentPlayer][4] = estate;
	state->deck[currentPlayer][5] = copper;
	state->deck[currentPlayer][6] = copper;
	state->deck[currentPlayer][7] = copper;
	state->deck[currentPlayer][8] = copper;
	state->deck[currentPlayer][9] = estate;

	state->numBuys = 1;
	correctHandCount = (randomHandCount + 2);
	adventurerCardEffect(card, drawntreasure, state, currentPlayer, temphand, z, cardDrawn);

	if(state->handCount[currentPlayer] == correctHandCount){
		printf("adventurerCardEffect(): PASS when correct number of cards (2 treasure cards) are added to the player's hand. Expected: %d, Actual: %d\n", correctHandCount, state->handCount[currentPlayer] );
		
	}
	else
		printf("adventurerCardEffect(): FAIL when correct number of cards (2 treasure cards) are added to the player's hand. Expected: %d, Actual: %d\n", correctHandCount, state->handCount[currentPlayer] );

}

int main(int argc, char *argv[]){
	int handCountUpper = 20;
	int handCountLower = 3;
	int randomHandCount;
	for(int i = 0; i < 50; i++){
		randomHandCount = (rand() % (handCountUpper - handCountLower + 1) + handCountLower);
		testAdventurerCardEffect(randomHandCount);
	}
	printf("Adventurer card effect test complete\n");	
	return 0;
}
