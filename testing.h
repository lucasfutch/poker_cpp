#include <stdlib.h>
#include <vector>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "rules.h"

// all the same suit
void testFlush() {
	Hand hand;
	hand.getCard(Card(1,1));
	hand.getCard(Card(1,2));
	hand.getCard(Card(1,3));
	hand.getCard(Card(1,4));
	hand.getCard(Card(1,5));
	std::cout << "FLUSH " << checkFlush(hand.showHand()) << std::endl;
}

// four of the same rank in different positions
void testFour() {
	Hand hand;
	hand.getCard(Card(1,4));
	hand.getCard(Card(2,4));
	hand.getCard(Card(3,4));
	hand.getCard(Card(0,4));
	hand.getCard(Card(1,5));

	Hand hand2;
	hand2.getCard(Card(1,7));
	hand2.getCard(Card(2,3));
	hand2.getCard(Card(3,3));
	hand2.getCard(Card(1,3));
	hand2.getCard(Card(2,3));

	std::cout << "FOUR A " << checkFour(hand.showHand()) << std::endl;
	std::cout << "FOUR B " << checkFour(hand2.showHand()) << std::endl;
}

// full house in different ordering or triplet and pair
void testFullHouse() {
	Hand hand;
	hand.getCard(Card(1,4));
	hand.getCard(Card(2,4));
	hand.getCard(Card(3,4));
	hand.getCard(Card(1,5));
	hand.getCard(Card(2,5));

	Hand hand2;
	hand2.getCard(Card(1,4));
	hand2.getCard(Card(2,4));
	hand2.getCard(Card(3,3));
	hand2.getCard(Card(1,3));
	hand2.getCard(Card(2,3));

	std::cout << "FULLHOUSE 32 " << checkFullHouse(hand.showHand()) << std::endl;
	std::cout << "FULLHOUSE 23 " << checkFullHouse(hand2.showHand()) << std::endl;
}

// testing without ace, low ace straight, and low ace straight incomplete
void testStraight() {
	Hand hand;
	hand.getCard(Card(1,10));
	hand.getCard(Card(2,9));
	hand.getCard(Card(3,8));
	hand.getCard(Card(2,7));
	hand.getCard(Card(1,6));

	Hand hand2;
	hand2.getCard(Card(1,12));
	hand2.getCard(Card(2,3));
	hand2.getCard(Card(3,2));
	hand2.getCard(Card(1,1));
	hand2.getCard(Card(2,0));

	Hand hand3;
	hand3.getCard(Card(1,12));
	hand3.getCard(Card(2,3));
	hand3.getCard(Card(3,2));
	hand3.getCard(Card(1,1));
	hand3.getCard(Card(2,1));

	std::cout << "STRAIGHT A " << checkStraight(hand.showHand()) << std::endl;
	std::cout << "STRAIGHT B " << checkStraight(hand2.showHand()) << std::endl;
	std::cout << "STRAIGHT C " << !checkStraight(hand3.showHand()) << std::endl;
}

// triplet in different positions
void testThree () {
	Hand hand;
	hand.getCard(Card(1,4));
	hand.getCard(Card(1,4));
	hand.getCard(Card(1,4));
	hand.getCard(Card(1,2));
	hand.getCard(Card(1,1));

	Hand hand2;
	hand2.getCard(Card(1,12));
	hand2.getCard(Card(2,3));
	hand2.getCard(Card(3,0));
	hand2.getCard(Card(1,0));
	hand2.getCard(Card(2,0));

	std::cout << "THREE A " << checkThree(hand.showHand()) << std::endl;
	std::cout << "THREE B " << checkThree(hand2.showHand()) << std::endl;
}

// two pairs in different positions
void testTwoPair() {
	Hand hand;
	hand.getCard(Card(1,9));
	hand.getCard(Card(2,9));
	hand.getCard(Card(1,5));
	hand.getCard(Card(2,5));
	hand.getCard(Card(1,1));

	Hand hand2;
	hand2.getCard(Card(1,10));
	hand2.getCard(Card(2,10));
	hand2.getCard(Card(3,5));
	hand2.getCard(Card(1,1));
	hand2.getCard(Card(2,1));

	std::cout << "TWOPAIR A " << checkTwoPair(hand.showHand()) << std::endl;
	std::cout << "TWOPAIR B " << checkTwoPair(hand.showHand()) << std::endl;
}

// pair testing in the middle of the hand
void testPair() {
	Hand hand;
	hand.getCard(Card(1,10));
	hand.getCard(Card(1,9));
	hand.getCard(Card(1,5));
	hand.getCard(Card(1,5));
	hand.getCard(Card(1,2));
	std::cout << "PAIR " << checkPair(hand.showHand()) << std::endl;
}

void runTesting() {
	testFlush();
	testFour();
	testFullHouse();
	testStraight();
	testThree();
	testTwoPair();
	testPair();
}
