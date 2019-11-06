#pragma once

#include <string>
#include "card.h"

namespace Player
{
	// En spelare har en poäng, ett namn, ett kort de håller i samt en hjälpfunktion för att skriva ut deras poäng
	struct Player
	{
		int score;
		std::string name;
		Card::Card* heldCard;

		Player(std::string);
		Player();

		void PrintScore();
	};
}