#include "cardgame.h"

// <memory> kr�vs f�r unique_ptr

#include <iostream>
#include <memory>
#include <string>

void Cardgame::StartGame()
{
	// Initialisera spelet
	PrepareDeck();
	AddPlayers();
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

void Cardgame::AddPlayers()
{
	auto numPlayers = 0;
	auto finished = false;

	std::cout << "You must add players to be able to play. You need at least two players." << std::endl;

	while (numPlayers < 2)
	{
		std::cout << "How many players do you want?" << std::endl;
		std::cin >> numPlayers;
		std::cout << std::endl;
	}

	for(int i = 0; i < numPlayers; i++)
	{
		std::cout << "What name does this player have?" << std::endl;

		std::string name;

		std::cin >> name;

		Player::Player::Player(name);

		std::cout << std::endl << name << " added to the game!" << std::endl;
	}
}

void Cardgame::DrawCard(Player::Player p)
{
	p.heldCard = deck.pop().get();
}
// J�mf�r kort. Returnera spelaren som vann
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

int Cardgame::GetNumberOfPlayers()
{
	return (int)players.size();
}

void Cardgame::AddScore(Player::Player winner)
{
	winner.score++;
}

// Kalla p� alla spelares funktion f�r att skriva ut deras po�ng
void Cardgame::PrintScores()
{
	for (auto p : players)
	{
		p.PrintScore();
	}

	auto winner = CompareCards();

	std::cout << std::endl << winner.name << " is in the lead!" << std::endl;
}

// St�da upp efter omg�ngen s� n�sta omg�ng b�rjar med rent state
void Cardgame::CleanUp()
{
	for (auto p : players)
	{
		deck.push(p.heldCard);
		p.heldCard = NULL;
	}

	deck.cleanUp();
}

// Avsluta spelet, skriv ut vinnaren
void Cardgame::EndGame()
{
	auto temp = 0;
	Player::Player winner;
	// Skriv ut alla spelares po�ng, och spara h�gsta po�ngen
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