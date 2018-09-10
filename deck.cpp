#include <iostream>
#include <random>
#include "deck.h"

Deck::Deck() {}

void Deck::makeDeck() {
	for (unsigned int i(0); i < SUITMAX; ++i)
    {
        for (unsigned int j(0); j < RANKMAX; ++j)
        {
            Card newCard(i, j);
            myDeck.push_back(newCard);
        }
    }
}

void Deck::printDeck() {
	for (auto& iter : myDeck) {
	    std::cout << iter.CardToString() << " ";
	}
	std::cout << "\n";
}

Card Deck::draw() {   
	if (!myDeck.empty()) {
	    Card cd = myDeck.back();
	    myDeck.pop_back();
	    return cd;
	}
	else {
		return Card(-1,-1);
	}
}

Card const& Deck::top() const {   
    return myDeck.back();
}

void Deck::shuffle() {
	std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(myDeck.begin(), myDeck.end(), g);
}

int Deck::getSize() {
	return myDeck.size();
}