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
	void getCard(Deck &deck);
	int binarySearch(std::vector<Card> hand, Card item, int low, int high);
	void insertionSortHand();
private:
	std::vector<Card> myHand;
};

#endif