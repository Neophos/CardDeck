#include "card.h"

Card::Card::Card(Suit s, int v)
{
	this->suit = s;
	this->value = v;
}

// Default
Card::Card::Card()
{
	this->suit = Suit::HEARTS;
	this->value = 0;
}
