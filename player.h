#pragma once

#include <string>
#include "card.h"

namespace Player
{
	struct Player
	{
		int score;
		std::string name;
		Card::Card heldCard;

		void PrintScore();
	};
}