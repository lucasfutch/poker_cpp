#ifndef CARD_H
#define CARD_H

#include <string>

const int SUITMAX(4);
const int RANKMAX(13);

class Card {
public:
	explicit Card();
	explicit Card(const int &suit, const int &rank);

	int getSuit() const;
	int getRank() const;
	std::string CardToString() const;
	void printCard();

private:
	int mySuit;
	int myRank;
};

#endif