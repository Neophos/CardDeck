#pragma once

// Definitionen av ett kort
namespace Card
{
	// Färger, lägre är bättre
	enum class Suit
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
		friend bool operator<(const Card& lhs, const Card& rhs)
		{
			lhs.value < rhs.value ? true : lhs.value == rhs.value ? lhs.suit < rhs.suit ? true : false : false;	
		}
		//friend bool operator>(const Card& lhs, const Card& rhs)
		//{
		//	return rhs < *lhs;
		//}
	};
}