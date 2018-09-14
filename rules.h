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
		std::cout << "Hand error." << std::endl;
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
		std::cout << "Hand error." << std::endl;
		return false;
	}
}

bool checkFullHouse(std::vector<Card> hand) {
	try {
		for (int i = 0; i < hand.size() - 4; i++) {
			// triplet comes first
			if ((hand[i].getRank() == hand[i + 1].getRank()) && (hand[i + 1].getRank() == hand[i + 2].getRank())) {
				if (hand[i + 3].getRank() == hand[i + 4].getRank()) {
					return true;
				}
			}
			// pair comes first
			else if (hand[i].getRank() == hand[i + 1].getRank()) {
				if ((hand[i + 2].getRank() == hand[i + 3].getRank()) && (hand[i + 3].getRank() == hand[i + 4].getRank())) {
					return true;
				}
			}
		}
		return false;
	}
	catch (int e) {
		std::cout << "Hand error." << std::endl;
		return false;
	}
}

bool checkStraight(std::vector<Card> hand) {
	try {
		// low ace straight check
		if ((hand[0].getRank() == 12) && (hand[1].getRank() == 3)) {
			for (int j = 2; j < hand.size(); j++) {
				if (hand[j].getRank() != (4 - j)) {
					return false;
				}
			}
			return true;
		}

		// normal straight check
		for (int i = 0; i < hand.size() - 1; i++) {
			if (hand[i].getRank() != (hand[i + 1].getRank() + 1)) {
				return false;
			}
		}

		return true;
	}
	catch (int e) {
		std::cout << "Hand error." << std::endl;
		return false;
	}
}

bool checkThree(std::vector<Card> hand) {
	int three;
	try {
		for (int i = 0; i < hand.size() - 2; i++) {
			three = ((1 << hand[i].getRank()) | (1 << hand[i + 1].getRank()) | (1 << hand[i + 2].getRank()));
			if ((1 << hand[i].getRank()) == three) {
				return true;
			}
		}
		return false;
	}
	catch (int e) {
		std::cout << "Hand error." << std::endl;
		return false;
	}
}

bool checkTwoPair(std::vector<Card> hand) {
	try {
		for (int i = 0; i < hand.size() - 3; i++) {
			if (hand[i].getRank() == hand[i + 1].getRank()) {
				for (int j = 2; j < hand.size() - 1; j++) {
					if (hand[j].getRank() == hand[j + 1].getRank()) {
						return true;
					}
				}
			}
		}
		return false;
	}
	catch (int e) {
		std::cout << "Hand error." << std::endl;
		return false;
	}
}

bool checkPair(std::vector<Card> hand) {
	int two;
	try {
		for (int i = 0; i < hand.size() - 1; i++) {
			two = ((1 << hand[i].getRank()) | (1 << hand[i + 1].getRank()));
			if ((1 << hand[i].getRank()) == two) {
				return true;
			}
		}
		return false;
	}
	catch (int e) {
		std::cout << "Hand error." << std::endl;
		return false;
	}
}

#endif