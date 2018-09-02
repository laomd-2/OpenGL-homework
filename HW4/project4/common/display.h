#ifndef DISPLAY_H
#define DISPLAY_H
#include <GL/glut.h>

double alignCenter(double factor)
{
	double cx = glutGet(GLUT_SCREEN_WIDTH);
	double cy = glutGet(GLUT_SCREEN_HEIGHT);
	double w = cy * factor;
	// 对窗口的大小进行初始化
    glutInitWindowSize(w, w);
    // 设置窗口出现的位置
    glutInitWindowPosition((cx - w) / 2, (cy - w) / 2);
	return w;
}

#endif // DISPLAY_H
