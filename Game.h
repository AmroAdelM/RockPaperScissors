#pragma once
#include "Player.h"
#include "Round.h"

class Game
{
public:
	Game(int numberOfRounds, std::shared_ptr<Player> userP, std::shared_ptr<Player> comP)
		: firstPlayer(userP), secondPlayer(comP), rounds(numberOfRounds)
	{
	}

	void startGame()
	{
		while (rounds != 0)
		{
			startRound();
			rounds--;
		}
		showFinalWinner();
	}

	void startRound()
	{
		firstPlayer->move();

		auto secondplayermove = secondPlayer->move();
		std::cout << "computer choice: " << (int)secondplayermove << std::endl;

		std::unique_ptr<Round> r(new Round(firstPlayer, secondPlayer));

		r->showRoundWinner();
	}

private:
	int rounds;
	std::shared_ptr<Player> firstPlayer;
	std::shared_ptr<Player> secondPlayer;



	void showFinalWinner()
	{
		if (firstPlayer->getWinsCount() > secondPlayer->getWinsCount())
			std::cout << "You won this game!" << std::endl;
		else if (firstPlayer->getWinsCount() < secondPlayer->getWinsCount())
			std::cout << "Computer won the game!" << std::endl;
		else
			std::cout << "It's a tie game!" << std::endl;
	}
};