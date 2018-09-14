#include <stdlib.h>
#include <vector>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "rules.h"
#include "testing.h"

int main() {
	Deck deck;
	deck.makeDeck(4, 13); // (4,13)
	deck.shuffle();

	Hand p1;
	p1.makeHand(deck);
	p1.sortHand();
	p1.printHand();

	// runTesting(); // expect 1 for all tests
	return 0;
}
