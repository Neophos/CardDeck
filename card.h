#pragma once

namespace Card
{
	enum class Suit
	{
		HEARTS = 0,
		SPADES,
		DIAMONDS,
		CLUBS
	};

	struct Card
	{
		Suit suit;
		int value;

		Card(Suit s, int v);
	};
}