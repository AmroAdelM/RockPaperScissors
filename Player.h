#pragma once
#include <iostream>
#include <random>
#include "GeneralConsts.h"

class Player
{
public:
	Choice getChoice()
	{
		return handChocie;
	}

	virtual Choice move() = 0;

	void increaseWins()
	{
		winsCount++;
	}

	int getWinsCount()
	{
		return winsCount;
	}

	Player() : handChocie(Choice::Rocks), winsCount(0)
	{
	}

protected:

	Choice handChocie;
	int winsCount;
};

class ComputerPlayer : public Player
{
public:
	Choice move() override
	{
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(0, CHOICES_COUNT - 1); // unbiased

		auto random_integer = uni(rng);
		handChocie = (Choice)random_integer;
		return handChocie;
	}

private:
	std::random_device rd;
};

class UserPlayer : public Player
{
public:
	Choice move() override
	{
		std::cout << "Enter Choice: (0: Rock, 1: Paper, 2: Scissor) " << std::endl;
		int input;
		do
		{
			std::cin >> input;
		} while (!validateUserInput(input));

		setChoice((Choice)input);

		return (Choice)input;
	}

	void setChoice(Choice c)
	{
		handChocie = c;
	}

private:

	bool validateUserInput(int input)
	{
		if (input < 3 && input >= 0)
			return true;
		return false;
	}
};
