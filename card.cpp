#include "card.h"
#include <iostream>

const std::string SUIT[SUITMAX+1]  = {"S", "H", "D", "C", "J"}; // Spades, Hearts, Diamonds, Clubs
const std::string RANK[RANKMAX+1]  = {"2","3","4","5","6","7","8","9","10","J","Q","K","A", "0"};

Card::Card() {
	mySuit = SUITMAX+1;
	myRank = RANKMAX+1;
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