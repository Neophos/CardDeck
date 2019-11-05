#pragma once

// Definitionen av ett kort
namespace Card
{
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

		Card(Suit s, int v);
		Card();

		// J�mf�relseoperator f�r att l�tt j�mf�ra korten och avg�ra vilket som �r v�rt mest
		friend bool operator> (const Card& lhs, const Card& rhs)
		{
			if (lhs.value > rhs.value)
			{
				return 1;
			}
			else if (lhs.value == rhs.value)
			{
				if (lhs.suit < rhs.suit)
				{
					return 1;
				}
			}
			return 0;
		}

		bool operator<(const Card& other) const
		{
			value < other.value ? true : value == other.value ? suit < other.suit ? true : false : false;	
		}
		bool operator>(const Card& other) const
		{
			return other < *this;
		}
	};
}