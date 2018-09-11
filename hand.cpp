#include <iostream>
#include "hand.h"

Hand::Hand() {}

void Hand::makeHand(Deck &deck) {
	for (int i = 0; i < 5; i++) {
		if (deck.getSize() > 0) {
			myHand.push_back(deck.draw());
		}
		else {
			return;
		}
	}
}

void Hand::printHand() {
	for (auto& iter : myHand) {
	    std::cout << iter.CardToString() << " ";
	}
	std::cout << "\n";
}
