#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"

void testrfAdventurer(){
	
	struct gameState *state = malloc(sizeof(struct gameState));
	int currentPlayer = 0;	

	state->handCount[currentPlayer] = 5;
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

	rfAdventurer(state);
	

	if(state->handCount[currentPlayer] == 7){
		printf("adventurerCardEffect(): PASS when correct number of cards (2 treasure cards) are added to the player's hand.\n");
		
	}
	else
		printf("adventurerCardEffect(): FAIL when correct number of cards (2 treasure cards) are added to the player's hand.\n");

}

int main(int argc, char *argv[]){
	testrfAdventurer();
	
	return 0;
}
