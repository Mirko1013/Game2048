#include "Cmd.h"

UpCommand::UpCommand(Game *gm) {
	game = gm;
}

bool UpCommand::check() {
	return game->canMoveUp();
}

void UpCommand::execute() {
	game->doUp();
}


DownCommand::DownCommand(Game *gm) {
	this->game = gm;
}

bool DownCommand::check() {
	return game->canMoveDown();
}

void DownCommand::execute() {
	game->doDown();
}

LeftCommand::LeftCommand(Game *gm) {
	this->game = gm;
}

bool LeftCommand::check() {
	return game->canMoveLeft();
}

void LeftCommand::execute() {
	game->doLeft();
}

RightCommand::RightCommand(Game *gm) {
	this->game = gm;
}

bool RightCommand::check() {
	return game->canMoveRight();
}

void RightCommand::execute() {
	game->doRight();
}