#include "player.h"
#include <iostream>

Player::Player::Player(std::string nam)
{
	name = nam;
	score = 0;
	heldCard = NULL;
}

Player::Player::Player()
{
	name = "";
	score = 0;
	heldCard = NULL;
}

void Player::Player::PrintScore()
{
	std::cout << name << "'s score is " << score << std::endl;
}

// Skriv ut valören och färgen på kortet
void Player::Player::PrintCard()
{
	std::cout << "the " << heldCard->value << " of ";
	switch (heldCard->suit)
	{
		case (Card::Suit)0:
			std::cout << "spades!" << std::endl;
			break;
		case (Card::Suit)1:
			std::cout << "hearts!" << std::endl;
			break;
		case (Card::Suit)2:
			std::cout << "diamonds!" << std::endl;
			break;
		case (Card::Suit)3:
			std::cout << "clubs!" << std::endl;
			break;
	}
}
