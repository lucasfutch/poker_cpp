#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include "deck.h"
#include "card.h"

class Hand {
public: 
	explicit Hand();
	void makeHand(Deck &deck);
	std::vector<Card> showHand();
	void printHand();
	void getCard(Deck &deck);
	void getCard(Card card);
	int binarySearch(std::vector<Card> hand, Card item, int low, int high);
	void sortHand();

	// bool checkFlush();
private:
	std::vector<Card> myHand;
};

#endif