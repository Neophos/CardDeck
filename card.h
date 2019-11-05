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

		// Jämförelseoperator för att lätt jämföra korten och avgöra vilket som är värt mest
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