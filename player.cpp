#include "player.h"
#include <iostream>

Player::Player::Player(std::string nam)
{
	name = nam;
	score = 0;
	heldCard = NULL;
}

Player::Player::Player()
{
	name = "";
	score = 0;
	heldCard = NULL;
}

void Player::Player::PrintScore()
{
	std::cout << name << "'s score is " << score << std::endl;
}
