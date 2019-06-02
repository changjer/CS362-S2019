#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"

void testCardEffectForTreasure_Map(){
	
	int choice1 = estate;
	int choice2 = estate;
	int choice3 = estate;
	struct gameState *state = malloc(sizeof(struct gameState));
	int handPos = 0;
	int bonus[100];
	int currentPlayer = 0;
	

	state->handCount[currentPlayer] = 5;
	state->hand[currentPlayer][0] = treasure_map;
	state->hand[currentPlayer][1] = estate;
	state->hand[currentPlayer][2] = estate;
	state->hand[currentPlayer][3] = estate;
	state->hand[currentPlayer][4] = treasure_map;
	
	state->deckCount[currentPlayer] = 10;
	state->deck[currentPlayer][0] = copper;
	state->deck[currentPlayer][1] = copper;
	state->deck[currentPlayer][2] = copper;
	state->deck[currentPlayer][3] = copper;
	state->deck[currentPlayer][4] = copper;
	state->deck[currentPlayer][5] = copper;
	state->deck[currentPlayer][6] = copper;
	state->deck[currentPlayer][7] = copper;
	state->deck[currentPlayer][8] = copper;
	state->deck[currentPlayer][9] = copper;
	
	cardEffect(treasure_map, choice1, choice2, choice3, state, handPos, bonus);
	
	if(state->deckCount[currentPlayer] == 14){
		printf("cardEffectForTreasure_Map(): PASS expected 14 cards in deck, actual = %d.\n", state->deckCount[currentPlayer]);
	}
	else
		printf("cardEffectForTreasure_Map(): FAIL expected 14 cards in deck, actual = %d.\n", state->deckCount[currentPlayer]);
	
}

int main(int argc, char *argv[]){
	testCardEffectForTreasure_Map();
	
	return 0;
}
