#ifndef CMD_H
#define CMD_H
#include"Game.h"
#include"Interface.h"

class UpCommand : public Command {
private:
	Game *game;
public:
	UpCommand(Game *game);
	void execute() override;
	bool check() override;
};

class DownCommand : public Command {
private:
	Game *game;
public:
	DownCommand(Game *game);
	void execute() override;
	bool check() override;
};

class LeftCommand : public Command {
private:
	Game *game;
public:
	LeftCommand(Game *game);
	void execute() override;
	bool check() override;
};

class RightCommand : public Command {
private:
	Game *game;
public:
	RightCommand(Game *game);
	void execute() override;
	bool check() override;
};

#endif