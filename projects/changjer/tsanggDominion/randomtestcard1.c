#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"

void testSmithyCardEffect(int startingHandCount){
	
	struct gameState *state = malloc(sizeof(struct gameState));
	int handPos = 0;
	int currentPlayer = 0;	

	state->handCount[currentPlayer] = startingHandCount;
	state->deckCount[currentPlayer] = 10;
	int tempHandCount = (state->handCount[currentPlayer] + 2);
	rfSmithy(state, handPos);

	if(state->handCount[currentPlayer] == tempHandCount){
		printf("smithyCardEffect(): PASS when correct number of cards remain player's hand. Expected: %d, Actual: %d\n", state->handCount[currentPlayer], tempHandCount);
	}
		
	else
		printf("smithyCardEffect(): Fail for correct number of cards remain player's hand. Expected: %d, Actual: %d\n", state->handCount[currentPlayer], tempHandCount);
	
}

int main(int argc, char *argv[]){	
	int upper = 50;
	int lower = 3;
	int randomNumber;
	for(int i = 0; i < 20; i++){
		randomNumber = (rand() % (upper - lower + 1) + lower);
		testSmithyCardEffect(randomNumber);
	}
	
	printf("All Smithy Card Tests completed\n");
	
	return 0;
}
