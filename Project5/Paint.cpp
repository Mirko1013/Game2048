#include"Paint.h"
#include<graphics.h>
#include<string>



Paint::Paint() : base_w(80), base_h(80) {	
	game = new Game();
}

Paint::~Paint() {
	delete game;
}


void Paint::drawEdge(int x, int y, int w, int h, int color, bool bdark = true) {
	setcolor(getchangcolor(color, 1.5f));
	line(x, y + h, x, y);
	lineto(x + w, y);
	if (bdark) {
		setcolor(getchangcolor(color, 0.8f));
	}
	lineto(x + w, y + h);
	lineto(x, y + h);
}

void Paint::drawFrame(int x, int y, int w, int h) {
	int color[] = { 0x400040, 0x600060, 0xa000a0, 0xff00ff,
		0xa000a0, 0x600060, 0x400040 };
	for (int width = 0; width < 7; ++width) {
		--x;
		--y;
		w += 2;
		h += 2;
		drawEdge(x, y, w, h, color[width]);
	}
}

void Paint::drawCell(int x, int y, int w, int h, int num, int color = 0x238e23) {
	--w;
	--h;
	setbkmode(TRANSPARENT);
	setfillcolor(color);
	bar(x + 1, y + 1, x + w, y + h);
	drawEdge(x, y, w, h, color);
	drawEdge(x + 1, y + 1, w - 2, h - 2, color);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setcolor(0xffffff);
	setfont(20, 20, "ºÚÌå");
	outtextxy(x + int(base_w / 2), y + int (base_h /2 ), std::to_string(num).c_str());	
}

void Paint::render() {
	cleardevice();
	drawFrame(base_w, base_h, size * base_w, size * base_h);
	

	setcolor(0xffffff);
	setfont(15, 15, "ºÚÌå");
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	std::string s = "Your score is : " + std::to_string(game->score);
	outtextxy((size + 3) * base_w, base_h /2 , s.c_str());
	
	
	if (game->isWon()) {
		outtextxy((size + 3) * base_w - base_w / 2, base_h, "You Win !!!");
	}else if (game->isOver()) {
		outtextxy((size + 5) * base_w - base_w / 2, base_h, "You Lose, press 'f1' to restart.");
	}


	for (int row = 0; row < size; ++row) {
		for (int col = 0; col < size; ++col) {
			if (game->board[row][col] != 0) {
				drawCell((col + 1) * base_w, (row + 1) * base_h, base_w,base_h, game->board[row][col]);
			}
		}
	}
}

void Paint::update() {
	render();

	key_msg key;

	int k = kbmsg();

	key = getkey();
		switch (key.key) {
		case VK_UP:
			if (key.msg == key_msg_up) {
				game->play(game->upCmd);
				render();
			}
			break;
		case VK_DOWN:
			if (key.msg == key_msg_up) {
				game->play(game->downCmd);
				render();
			}
			break;
		case VK_LEFT:
			if (key.msg == key_msg_up) {
				game->play(game->leftCmd);
				render();
			}
			break;
		case VK_RIGHT:
			if (key.msg == key_msg_up) {
				game->play(game->rightCmd);
				render();
			}
			break;
		case VK_F1:
			game->restart();
			render();
			break;
		default:
			break;		

	}
}

