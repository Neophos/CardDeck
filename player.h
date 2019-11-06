#pragma once

#include <string>
#include "card.h"

namespace Player
{
	// En spelare har en po�ng, ett namn, ett kort de h�ller i samt en hj�lpfunktion f�r att skriva ut deras po�ng
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