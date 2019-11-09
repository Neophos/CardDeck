#include "player.h"
#include <iostream>
#include <string>
#include <array>

namespace Player {

	// Lookup-tabeller för namnen på kort
	std::array<std::string, 4> suits = 
	{
		"spades",
		"hearts",
		"diamonds",
		"clubs"
	};

	std::array<std::string, 13> values =
	{
		"ace",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"jack",
		"queen",
		"king"
	};

	Player::Player(std::string _name)
	{
		name = _name;
		score = 0;
		heldCard = nullptr;
	}

	Player::Player()
	{
		name = "";
		score = 0;
		heldCard = nullptr;
	}

	void Player::PrintScore() const
	{
		std::cout << name << "'s score is " << score << std::endl;
	}

	// Skriv ut valören och färgen på kortet
	void Player::PrintCard() const
	{
		std::cout << "the " << values[heldCard->value] << " of " << suits[heldCard->suit] << "!" << std::endl;
	}
}