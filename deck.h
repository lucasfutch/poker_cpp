#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include <fstream>
#include "card.h"

const int DECKSIZE(52);

class Deck {
public:
	explicit Deck();
	void makeDeck();
	void printDeck();
	Card draw();
	Card const& top() const;
	void shuffle();
	int getSize();
private:
	std::vector<Card> myDeck;
};

#endif