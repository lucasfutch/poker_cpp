#include <stdlib.h>
#include <vector>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "hand.h"

int main() {
	Deck deck;
	deck.makeDeck(4,13);
	deck.printDeck();
	deck.shuffle();

	Hand p1;
	p1.makeHand(deck);
	p1.printHand();

	return 0;
}
