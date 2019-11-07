#pragma once

#include "carddeck.h"
#include "card.h"
#include "player.h"
#include <vector>
#include <random>
#include <algorithm>

// Deklarationer av alla funktioner som krävs för spelet
namespace Cardgame
{
	void StartGame();
	void EndGame();
	void PrepareDeck();
	void ShuffleDeck();
	void AddScore(Player::Player);
	void AddPlayers();
	// DrawCard riktar sig explicit till en spelare som får kortet
	void DrawCard(Player::Player);
	// CompareCards returnerar den vinnande spelaren
	Player::Player CompareCards();
	int GetNumberOfPlayers();
	void PrintScores();
	void CleanUp();
	void AskForRematch();
	bool GetGameRunning();
	Player::Player GetPlayer(int);


	// En stack av 52 kort
	static auto deck = CardDeck::Stack<Card::Card, 52>();

	// Stöd för arbiträrt många spelare ifall man vill
	static std::vector<Player::Player> players;

	static bool gameRunning;
}