#include "card.h"
#include <iostream>

const std::string SUIT[SUITMAX]  = {"S", "H", "D", "C"}; // Spades, Hearts, Diamonds, Clubs
const std::string RANK[RANKMAX]  = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

Card::Card() {
	mySuit = 0;
	myRank = 0;
}

Card::Card(const int &suit, const int &rank) : mySuit(suit), myRank(rank) {
}

int Card::getSuit() const {
	return mySuit;
}

int Card::getRank() const {
	return myRank;
}

std::string Card::CardToString() const {
	return SUIT[getSuit()] + RANK[getRank()];
}

void Card::printCard() {
	std::cout << CardToString() << std::endl;
}