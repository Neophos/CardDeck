#include "cardgame.h"

int main()
{
	Cardgame::StartGame();

	while (Cardgame::gameRunning)
	{
		Cardgame::ShuffleDeck();

		for(int i = 0; i < Cardgame::players.size - 1; i++)
		{
			Cardgame::DrawCard(Cardgame::players.at(i));
		}

		Cardgame::CompareCards();
		Cardgame::PrintScores();
		Cardgame::CleanUp();
	}

	Cardgame::EndGame();

	return 0;
}