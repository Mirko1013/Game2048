#pragma once
#include<graphics.h>
#include"Game.h"

class Paint {
private:

	Game *game;

	static const int size = 5;

	int base_w;
	int base_h;

	static int dealbit(int a, float dt) {
		a = int(a * dt);
		if (a>255)    a = 255;
		else if (a<0) a = 0;
		return a;
	}
	static int getchangcolor(int color, float t) {
		int r = EGEGET_R(color), g = EGEGET_G(color), b = EGEGET_B(color);
		r = dealbit(r, t);
		g = dealbit(g, t);
		b = dealbit(b, t);
		return EGERGB(r, g, b);
	}

public:
	Paint();
	~Paint();
	void drawEdge(int x, int y, int w, int h, int color, bool bdark);
	void drawFrame(int x, int y, int w, int h);
	void drawCell(int x, int y, int w, int h, int num, int color);
	void render();

	void update();

	static const int global_width = 1100;
	static const int global_height = 560;
};
