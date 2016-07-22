#include"Paint.h"
#include "ege/fps.h"

int main() {
	initgraph(Paint::global_width, Paint::global_height);
	Paint paint;
	int nfps = 120;
	fps ui_fps;
	setrendermode(RENDER_MANUAL);
	for (; is_run(); delay_fps(nfps)) {
		paint.update();
	}
	return 0;
}