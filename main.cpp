#include "cardgame.h"

int main()
{
	Cardgame::StartGame();

	while (Cardgame::gameRunning)
	{
		Cardgame::ShuffleDeck();

		for(int i = 0; i < Cardgame::GetNumberOfPlayers(); i++)
		{
			Cardgame::DrawCard(Cardgame::players[i]);
		}

		Cardgame::AddScore(Cardgame::CompareCards());
		Cardgame::PrintScores();
		Cardgame::CleanUp();
	}

	Cardgame::EndGame();

	return 0;
}