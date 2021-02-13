#include <iostream>
#include "Game.h"
int main()
{
	Game game(3, std::shared_ptr< UserPlayer>(new UserPlayer()), std::shared_ptr< ComputerPlayer>(new ComputerPlayer()));
	game.startGame();
}