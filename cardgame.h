#pragma once

#include "carddeck.h"
#include "card.h"
#include "player.h"
#include <vector>
#include <random>
#include <algorithm>

// Deklarationer av alla funktioner som kr�vs f�r spelet
namespace Cardgame
{
	void StartGame();
	void EndGame();
	void PrepareDeck();
	void ShuffleDeck();
	void AddScore(Player::Player);
	void AddPlayers();
	// DrawCard riktar sig explicit till en spelare som f�r kortet
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

	// St�d f�r arbitr�rt m�nga spelare ifall man vill
	static std::vector<Player::Player> players;

	static bool gameRunning;
}