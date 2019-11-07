#include "cardgame.h"

// <memory> krävs för unique_ptr

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
// Eventuella förberedelser som måste göras på leken
void Cardgame::PrepareDeck()
{
	for (int i = 0; i < 4; i++)
	{
		for (int k = 1; k <= 13; k++)
		{
			deck.push(new Card::Card((Card::Suit)i, k));
		}
	}
}

// Blanda leken
void Cardgame::ShuffleDeck()
{
	deck.randomise();
}

// Skapa spelare och lägg dom i container
void Cardgame::AddPlayers()
{
	auto numPlayers = 0;
	auto finished = false;

	std::cout << "You must add players to be able to play. You need at least two players." << std::endl;

	while (numPlayers < 2)
	{
		// Sanity check på att det bara matas in siffror
		std::cout << "How many players do you want?" << std::endl;
		while (!(std::cin >> numPlayers)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Honestly. How many players?" << std::endl;
		}

		if (numPlayers < 2)
		{
			std::cout << "I said at least two players." << std::endl;
		}
	}

	std::cout << "Number of players will be " << numPlayers << std::endl;

	// Skapa alla spelare
	for(int i = 0; i < numPlayers; i++)
	{
		std::cout << "What name does this player have?" << std::endl;

		std::string name;

		std::cin >> name;

		players.emplace_back(Player::Player::Player(name));

		std::cout << std::endl << name << " added to the game!" << std::endl;
	}
}

// Ge en spelare ett kort
void Cardgame::DrawCard(Player::Player p)
{
	p.heldCard = deck.pop();

	std::cout << p.name << " drew the card ";
	p.PrintCard();
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

int Cardgame::GetNumberOfPlayers()
{
	return (int)players.size();
}

void Cardgame::AddScore(Player::Player winner)
{
	winner.score++;
}

// Kalla på alla spelares funktion för att skriva ut deras poäng
void Cardgame::PrintScores()
{
	for (auto p : players)
	{
		p.PrintScore();
	}

	auto winner = CompareCards();

	std::cout << std::endl << winner.name << " is in the lead!" << std::endl;
}

// Städa upp efter omgången så nästa omgång börjar med rent state
void Cardgame::CleanUp()
{
	for (auto p : players)
	{
		deck.push(p.heldCard);
		p.heldCard = NULL;
	}

	deck.cleanUp();

	AskForRematch();
}

// Avsluta spelet, skriv ut vinnaren
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

// Se ifall spelarna vill fortsätta
void Cardgame::AskForRematch()
{
	std::cout << "Do you wish to play another round? Yes/No" << std::endl;

	std::string temp;

	do
	{
		std::cin >> temp;
		std::transform(temp.begin(), temp.end(), temp.begin(), std::tolower);
		std::cout << std::endl;
	} while ((temp != "yes" || temp != "no"));

	if (temp == "no")
	{
		Cardgame::gameRunning = false;
	}
}

bool Cardgame::GetGameRunning()
{
	return gameRunning;
}

Player::Player Cardgame::GetPlayer(int pos)
{
	return players.at(pos);
}
