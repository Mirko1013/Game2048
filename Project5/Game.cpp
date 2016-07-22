#include<stdlib.h>
#include<time.h>
#include "Game.h"
#include"Cmd.h"
#include <iostream>


Game::Game() : numberOfEmptyCells(size * size), score(0), win(false), lose(false) {
	initChessboard();
	srand(time(0));
	print();
	upCmd = new UpCommand(this);
	downCmd = new DownCommand(this);
	leftCmd = new LeftCommand(this);
	rightCmd = new RightCommand(this);
}

Game::~Game() {
	delete upCmd;
	delete downCmd;
	delete leftCmd;
	delete rightCmd;
}

void Game::initChessboard() {
	for (int row = 0; row < size; ++row) {
		for (int col = 0; col < size; ++col) {
			board[row][col] = 0;
		}
	}
	
	for (int i = 0; i < numberOfStartCells; ++i) {
		addRandomCell();
	}
}

void Game::addRandomCell() {
	int value = rand() % 2 + 1;
	int random = getRandomAvailableCell();
	int row = random / size;
	int col = random % size;
	board[row][col] = value;

	--numberOfEmptyCells;
}

int Game::getRandomAvailableCell() const {
	while (1) {
		int random = rand() % (size * size);
		int row = random / size;
		int col = random % size;
		if (board[row][col] == 0) {
			return random;
		}
	}
	return -1;
}

void Game::clearCell(int row, int col) {
	board[row][col] = 0;
	++numberOfEmptyCells;
}

bool Game::canMoveUp() const {
	for (int col = 0; col < size; ++col) {
		bool result = false;
		for (int row = 0; row < size; ++row) {
			if (board[row][col] == 0) {
				result = true;
			}
			else if ( (row != 0 && board[row][col] == board[row - 1][col]) || result ) {
				return true;
			}
		}
	}
	return false;
}

void Game::doUp() {
	for (int col = 0; col < size; ++col) {
		int pAva = 0; 
		int pFir = -1;
		int pSec = -1;

		for (int row = 0; row < size; ++row) {
			if (board[row][col] != 0) {
				if (pFir == -1) {
					pFir = row;
				}
				else {
					if (pSec == -1) {
						pSec = row;
						if (board[pFir][col] == board[pSec][col]) {
							board[pAva][col] = 2 * board[pFir][col];

							if (pFir != pAva) {
								clearCell(pFir, col);
								--numberOfEmptyCells;
							}
							clearCell(pSec, col);
							score = board[pAva][col] > score ? board[pAva][col] : score;
							pFir = -1;					
						}
						else {							
							if (pFir != pAva) {
								board[pAva][col] = board[pFir][col];
								clearCell(pFir, col);
								--numberOfEmptyCells;
							}
							pFir = pSec;
						}

						++pAva;
						pSec = -1;
					}
				
				}
			
			}
		}

		if (pFir != -1 && pAva != pFir) {
			board[pAva][col] = board[pFir][col];
			clearCell(pFir, col);
			--numberOfEmptyCells;
		}

	}
}

bool Game::canMoveDown() const {
	for (int col = 0; col < size; ++col) {
		bool result = false;
		for (int row = size - 1; row >= 0; --row) {
			if (board[row][col] == 0) {
				result = true;
			}
			else if ((row != size -1 && board[row][col] == board[row + 1][col]) || result) {
				return true;
			}
		}
	}
	return false;
}

void Game::doDown() {
	for (int col = 0; col < size; ++col) {
		int pAva = size - 1;
		int pFir = -1;
		int pSec = -1;

		for (int row = size - 1; row >= 0; --row) {
			if (board[row][col] != 0) {
				if (pFir == -1) {
					pFir = row;
				}
				else {
					if (pSec == -1) {
						pSec = row;
						if (board[pFir][col] == board[pSec][col]) {
							board[pAva][col] = 2 * board[pFir][col];

							if (pFir != pAva) {
								clearCell(pFir, col);
								--numberOfEmptyCells;
							}
							clearCell(pSec, col);
							score = board[pAva][col] > score ? board[pAva][col] : score;
							pFir = -1;
						}
						else {
							if (pFir != pAva) {
								board[pAva][col] = board[pFir][col];
								clearCell(pFir, col);
								--numberOfEmptyCells;
							}
							pFir = pSec;
						}

						--pAva;
						pSec = -1;
					}

				}

			}
		}

		if (pFir != -1 && pAva != pFir) {
			board[pAva][col] = board[pFir][col];
			clearCell(pFir, col);
			--numberOfEmptyCells;
		}

	}
}

bool Game::canMoveLeft() const {
	for (int row = 0; row < size; ++row) {
		bool result = false;
		for (int col = 0; col < size; ++col) {
			if (board[row][col] == 0) {
				result = true;
			}
			else if ((col != 0 && board[row][col] == board[row][col - 1]) || result) {
				return true;
			}
		}
	}
	return false;
}

void Game::doLeft() {
	for (int row = 0; row < size; ++row) {
		int pAva = 0;
		int pFir = -1;
		int pSec = -1;
		for (int col = 0; col < size; ++col) {
			if (board[row][col] != 0) {
				if (pFir == -1) {
					pFir = col;
				}
				else {
					if (pSec == -1) {
						pSec = col;
						if (board[row][pFir] == board[row][pSec]) {
							board[row][pAva] = 2 * board[row][pFir];
							if (pFir != pAva) {
								clearCell(row, pFir);
								--numberOfEmptyCells;
							}
							clearCell(row, pSec);
							score = board[row][pAva] > score ? board[row][pAva] : score;

							pFir = -1;
						}
						else {
							if (pFir != pAva) {
								board[row][pAva] = board[row][pFir];
								clearCell(row, pFir);
								--numberOfEmptyCells;
							}	

							pFir = pSec;
						}

						++pAva;
						pSec = -1;
					}

				}		
			}
		}
		if (pFir != -1 && pAva != pFir) {
			board[row][pAva] = board[row][pFir];
			clearCell(row, pFir);
			--numberOfEmptyCells;		
		}
	}
}

bool Game::canMoveRight()const {
	for (int row = 0; row < size; ++row) {
		bool result = false;
		for (int col = size - 1; col >= 0; --col) {
			if (board[row][col] == 0) {
				result = true;
			}
			else if ((col != size - 1 && board[row][col] == board[row][col + 1]) || result) {
				return true;
			}
		}
	}
	return false;
}

void Game::doRight() {
	for (int row = 0; row < size; ++row) {
		int pAva = size -1;
		int pFir = -1;
		int pSec = -1;
		for (int col = size - 1; col >= 0; --col) {
			if (board[row][col] != 0) {
				if (pFir == -1) {
					pFir = col;
				}
				else {
					if (pSec == -1) {
						pSec = col;
						if (board[row][pFir] == board[row][pSec]) {
							board[row][pAva] = 2 * board[row][pFir];
							if (pFir != pAva) {
								clearCell(row, pFir);
								--numberOfEmptyCells;
							}
							clearCell(row, pSec);
							score = board[row][pAva] > score ? board[row][pAva]:score;

							pFir = -1;
						}
						else {
							if (pFir != pAva) {
								board[row][pAva] = board[row][pFir];
								clearCell(row, pFir);
								--numberOfEmptyCells;
							}

							pFir = pSec;
						}

						--pAva;
						pSec = -1;
					}

				}
			}
		}
		if (pFir != -1 && pAva != pFir) {
			board[row][pAva] = board[row][pFir];
			clearCell(row, pFir);
			--numberOfEmptyCells;
		}
	}

}

void Game::play(Command *cmd) {
	if (!cmd->check()) return;
	cmd->execute();
	addRandomCell();

	if (score == 2048) {
		win = true;
	}

	if (numberOfEmptyCells == 0 && !(canMoveDown()|| canMoveUp() || canMoveLeft() || canMoveRight() )) {
		lose = true;
	}

	//print();
}

void Game::restart() {
	initChessboard();
	win = false;
	lose = false;
}

void Game::print() const{
	std::cout << "================================================================" << std::endl;
	std::cout << "Score: " << score << std::endl;
	std::cout << "Empty: " << numberOfEmptyCells << std::endl;

	if (isTerminated()) {
		if (win)
			std::cout << "YOU WIN!!!" << std::endl;
		else if (lose)
			std::cout << "YOU LOSE!!!" << std::endl;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%4d ", board[i][j]);
		}
		std::cout << std::endl;
	}
	std::cout << "================================================================" << std::endl << std::endl;
}

bool Game::isOver() const {
	return lose;
}

bool Game::isWon() const {
	return win;
}

bool Game::isTerminated() const{
	return win || lose;
}