#include <iostream>
#include <random>
#include "deck.h"

Deck::Deck() {}

void Deck::makeDeck(int suit, int rank) {
	try {
		for (int i = 0; i < suit; ++i) {
	        for (unsigned int j(0); j < rank; ++j)
	        {
	            Card newCard(i, j);
	            if (newCard.getSuit() == SUITMAX || newCard.getRank() == RANKMAX) {
	      			myDeck.clear();
	            	throw 1;
	            }
	            myDeck.push_back(newCard);
	        }
   		}
	}
	
	catch (int e) {
		std::cout << "Exceeded SUIT or RANK MAX." << std::endl;
	}
}

void Deck::printDeck() {
	try {
		if (myDeck.empty()) {
			throw 1;
		}

		for (auto& iter : myDeck) {
	    	std::cout << iter.cardToString() << " ";
		}
		std::cout << "\n";
	}
	catch (int e) {
		std::cout << "Deck is empty!" << std::endl;
	}
}

Card Deck::draw() {   
	if (!myDeck.empty()) {
	    Card drawCard = myDeck.back();
	    myDeck.pop_back();
	    return drawCard;
	}
	else {
		return Card();
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