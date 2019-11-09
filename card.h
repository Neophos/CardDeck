#pragma once

// Definitionen av ett kort
namespace Card
{
	// Färger, lägre är bättre
	enum Suit
	{
		SPADES = 0,
		HEARTS,
		DIAMONDS,
		CLUBS
	};

	struct Card
	{
		Suit suit;
		int value;

		// En vanlig och en default constructor
		Card(Suit s, int v);
		Card();

		// Jämförelseoperator för att lätt jämföra korten och avgöra vilket som är värt mest
		bool operator<(const Card& rhs) const
		{
			return value < rhs.value ? true : value == rhs.value ? suit > rhs.suit ? true : false : false;	
		}

		bool operator>(const Card& rhs) const
		{
			return rhs < *this;
		}
	};
}