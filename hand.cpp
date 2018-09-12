#include <iostream>
#include "hand.h"

Hand::Hand() {}

void Hand::makeHand(Deck &deck) {
	try {
		for (int i = 0; i < 5; i++) {
			if (deck.getSize() > 0) {
				myHand.push_back(deck.draw());
			}
			else {
				throw 1;
			}
		}
	}
	catch (int e) {
		std::cout << "No more cards!" << std::endl;
	}
}

void Hand::printHand() {
	for (auto& iter : myHand) {
	    std::cout << iter.cardToString() << " ";
	}
	std::cout << "\n";
}

void Hand::getCard(Deck &deck) {
	try {
		if (deck.getSize() > 0) {
			myHand.push_back(deck.draw());
		}
		else {
			throw 1;
		}
	}
	catch (int e) {
		std::cout << "No more cards!" << std::endl;
	}
}

int Hand::binarySearch(std::vector<Card> hand, Card item, int low, int high) {
	if (high <= low) 
		return (item.getRank() > hand[low].getRank()) ? low : (low + 1);

	int mid = (low + high)/2;

	if (item.getRank() > hand[mid].getRank())
		return binarySearch(hand, item, low, mid - 1);

	return binarySearch(hand, item, mid + 1, high);
}

void Hand::binarySortHand() {
	int i, j, k, loc;
	Card selected;

	for (i = 1; i < myHand.size(); i++) {
		j = i - 1;
		selected = myHand[i];

		loc = binarySearch(myHand, selected, 0, j);

		while (j >= loc) {
			myHand[j + 1] = myHand[j];
			j--;
		}
		myHand[j+1] = selected;
	}
	
}

/*

0	1	2	3	4
k	4	a 	k	8
	i
j
	sel
loc 

bs(hand, 6, 0, 0)
loc = 0







*/




