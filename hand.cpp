#include <iostream>
#include "hand.h"

Hand::Hand() {}

void Hand::makeHand(Deck &deck) {
	// while (!deck.empty()) {
	for (int i = 0; i < 5; i++) {
		myHand.push_back(deck.draw());
	}
	// }
}

void Hand::printHand() {
	for (auto& iter : myHand) {
	    std::cout << iter.CardToString() << " ";
	}
	std::cout << "\n";
}
