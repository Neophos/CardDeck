#pragma once

// Definitionen av ett kort
namespace Card
{
	// F�rger, l�gre �r b�ttre
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

		// J�mf�relseoperator f�r att l�tt j�mf�ra korten och avg�ra vilket som �r v�rt mest
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