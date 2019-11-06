#pragma once

// Definitionen av ett kort
namespace Card
{
	// F�rger, l�gre �r b�ttre
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

		// J�mf�relseoperator f�r att l�tt j�mf�ra korten och avg�ra vilket som �r v�rt mest
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