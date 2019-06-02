#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"

void testSmithyCardEffect(){
	
	int card = 1; 
	struct gameState *state = malloc(sizeof(struct gameState));
	int handPos = 0;
	int currentPlayer = 0;	

	state->handCount[currentPlayer] = 1;
	state->deckCount[currentPlayer] = 10;
	smithyCardEffect(card, state, handPos, currentPlayer);
	if(state->handCount[currentPlayer] == 3){
		printf("smithyCardEffect(): PASS when correct number of cards remain player's hand.\n");
	}
	else
		printf("smithyCardEffect(): FAIL when correct number of cards remain player's hand.\n");
	
}

int main(int argc, char *argv[]){
	testSmithyCardEffect();
	
	return 0;
}
