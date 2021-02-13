#pragma once

#define CHOICES_COUNT 3

typedef enum class choice {

	Rocks = 0,
	Papers = 1,
	Scissors = 2
} Choice;

typedef enum class winner {

	Tie = 0,
	Player1Won = 1,
	Player2Won = 2
} Result;


Result result[3][3] = { {Result::Tie, Result::Player2Won, Result::Player1Won},
						{Result::Player1Won, Result::Tie, Result::Player2Won},
						{Result::Player2Won, Result::Player1Won, Result::Tie} };