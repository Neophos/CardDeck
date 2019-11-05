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
	// Skapa kortleken, 13 av varje kort av de fyra f�rgerna
	for (int i = 0; i < 4; i++)
	{
		for (int k = 1; k <= 13; k++)
		{
			deck.push(std::make_unique<Card::Card>((Card::Suit)(i), k));
		}
	}

	int g = 1;
}

void Cardgame::ShuffleDeck()
{
	deck.randomise();
}

void Cardgame::DrawCard(Player::Player p)
{
	p.heldCard = deck.pop();
}
// J�mf�r kort. Returnera spelaren som vann
Player::Player Cardgame::CompareCards()
{
	Player::Player winningPlayer;

	for (int i = 0; i < players.size - 1; i++)
	{

	}
}

void Cardgame::PrintScores()
{
	for (int i = 0; i < players.size - 1; i++)
	{
		players.at(i).PrintScore();
	}
}

void Cardgame::CleanUp()
{
	for (int i = 0; i < players.size - 1; i++)
	{
		deck.push(players.at(i).heldCard);
	}
}

void Cardgame::EndGame()
{
	auto temp = 0;
	Player::Player winner;
	// Skriv ut alla spelares po�ng, och spara h�gsta po�ngen
	for (int i = 0; i < players.size - 1; i++)
	{
		players.at(i).PrintScore();

		if (temp < players.at(i).score)
		{
			winner = players.at(i);
		}
	}

	std::cout << std::endl << winner.name << " is the winner of the game!" << std::endl;
}