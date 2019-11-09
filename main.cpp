#include "cardgame.h"

int main()
{
	Cardgame::StartGame();

	while (Cardgame::GetGameRunning())
	{
		Cardgame::ShuffleDeck();

		for(int i = 0; i < Cardgame::GetNumberOfPlayers(); i++)
		{
			Cardgame::DrawCard(Cardgame::GetPlayer(i));
		}

		Cardgame::AddScore(const_cast<Player::Player*>(Cardgame::CompareCards()));
		Cardgame::PrintScores();
		Cardgame::CleanUp();
	}

	Cardgame::EndGame();

	return 0;
}