#ifndef GAME_H
#define GAME_H
#include"Interface.h"

class Game {
private:
	
	bool lose;
	bool win;

	int numberOfEmptyCells;

	static const int size = 5;
	static const int numberOfStartCells = 2;



	void initChessboard();
	int getRandomAvailableCell() const;
	void clearCell(int, int);

public:	
	Command *upCmd;
	Command *downCmd;
	Command *leftCmd;
	Command *rightCmd;
	int score;

	Game();
	~Game();

	void addRandomCell();
	void play(Command *);
	bool canMoveUp() const;
	bool canMoveDown() const;
	bool canMoveLeft() const;
	bool canMoveRight() const;
	void doUp();
	void doDown();
	void doLeft();
	void doRight();

	void restart();


	void print() const;

	bool isOver() const;
	bool isWon() const;
	bool isTerminated() const;
	int board[size][size];

};

#endif