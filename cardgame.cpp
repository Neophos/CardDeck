#include "cardgame.h"

#include <iostream>
#include <memory>

void Cardgame::StartGame()
{
	// Initialisera spelet
	PrepareDeck();
	ShuffleDeck();

	gameRunning = true;
}

void Cardgame::PrepareDeck()
{

}

void Cardgame::ShuffleDeck()
{
	deck.randomise();
}

void Cardgame::DrawCard(Player::Player p)
{
	p.heldCard = deck.pop().get();
}
// Jämför kort. Returnera spelaren som vann
Player::Player Cardgame::CompareCards()
{
	auto winner = Player::Player();

	for (auto p : players)
	{
		if (p.heldCard > winner.heldCard)
		{
			winner = p;
		}
	}

	return winner;
}

void Cardgame::PrintScores()
{
	for (auto p : players)
	{
		p.PrintScore();
	}
}

void Cardgame::CleanUp()
{
	for (auto p : players)
	{
		p.heldCard = NULL;
	}

	deck.cleanUp();
}

void Cardgame::EndGame()
{
	auto temp = 0;
	Player::Player winner;
	// Skriv ut alla spelares poäng, och spara högsta poängen
	for (auto p : players)
	{
		p.PrintScore();

		if (temp < p.score)
		{
			winner = p;
		}
	}

	std::cout << std::endl << winner.name << " is the winner of the game!" << std::endl;
}