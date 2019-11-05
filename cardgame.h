#pragma once

#include "carddeck.h"
#include "card.h"
#include "player.h"
#include <vector>
#include <random>
#include <algorithm>

namespace Cardgame
{
	void StartGame();
	void EndGame();
	void PrepareDeck();
	void ShuffleDeck();
	void DrawCard(Player::Player);
	Player::Player CompareCards();
	void PrintScores();
	void CleanUp();

	static auto deck = CardDeck::Stack<std::unique_ptr<Card::Card>, 52>();

	static std::vector<Player::Player> players;

	static bool gameRunning;
}