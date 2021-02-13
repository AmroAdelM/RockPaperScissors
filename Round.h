#pragma once
#include "Player.h"

class Round
{
public:
	Round(std::shared_ptr<Player> a1, std::shared_ptr<Player> a2): player1( a1), player2(a2)
	{
	}

	Result getRoundResult()
	{
		return result[(int)player1->getChoice()][(int)player2->getChoice()];
	}

	void checkRoundWinner()
	{
		increaseWinnerCount(getRoundResult());
	}

	void showRoundWinner()
	{
		//this assumes a user/computer scenario which isn't always the case like in this exact scenario
		//so it should be in Game class but logically it belongs to the round class so hwg
		auto winner = getRoundResult();
		increaseWinnerCount(winner);

		if (winner == Result::Player1Won)
			std::cout << "You won this round!" << std::endl;
		else if (winner == Result::Player2Won)
			std::cout << "Computer won this round!" << std::endl;
		else
			std::cout << "It's a tie round!" << std::endl;
	}

private:
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;

	void increaseWinnerCount(Result win)
	{
		if (win == Result::Player1Won)
			player1->increaseWins();
		else if (win == Result::Player2Won)
			player2->increaseWins();
	}
};
