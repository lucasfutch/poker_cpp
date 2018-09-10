#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include <fstream>
#include "deck.h"
#include "card.h"

class Hand {
public: 
	explicit Hand();
	void makeHand(Deck &deck);
	void printHand();
private:
	std::vector<Card> myHand;
};

#endif