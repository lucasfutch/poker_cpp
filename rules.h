#ifndef RULES_H
#define RULES_H

#include <vector>
#include <iostream>
// #include "deck.h"
// #include "card.h"
#include "hand.h"

bool checkFlush(std::vector<Card> hand) {
	try {
		int suits = hand[0].getSuit();
		for (int i = 1; i < hand.size(); i++) {
			if (suits != hand[i].getSuit()) {
				return false;
			}
		}
		return true;
	}
	catch (int e) {
		std::cout << "Hand error. Not enough cards." << std::endl;
		return false;
	}
}

bool checkFour(std::vector<Card> hand) {
	int four;
	try {
		for (int i = 0; i < hand.size() - 3; i++) {
			four = ((1 << hand[i].getRank()) 	| (1 << hand[i + 1].getRank()) | 
					(1 << hand[i + 2].getRank())| (1 << hand[i + 3].getRank()));
			if ((1 << hand[i].getRank()) == four) {
				return true;
			}
		
		}
		return false;
	}
	catch (int e) {
		std::cout << "Hand error. Not enough cards." << std::endl;
		return false;
	}
}

bool checkFullHouse(std::vector<Card> hand) {
	return false;
}

bool checkStraight(std::vector<Card> hand) {
	return false;
}

bool checkThree(std::vector<Card> hand) {
	return false;
}

bool checkTwoPair(std::vector<Card> hand) {
	return false;
}

bool checkPair(std::vector<Card> hand) {
	return false;
}

#endif