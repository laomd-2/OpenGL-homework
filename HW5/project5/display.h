#ifndef DISPLAY_H
#define DISPLAY_H
#include <GL/glut.h>

double alignCenter(double factor)
{
	int cx = glutGet(GLUT_SCREEN_WIDTH);
	int cy = glutGet(GLUT_SCREEN_HEIGHT);
	int w = (int)(cy * factor);
	// 对窗口的大小进行初始化
    glutInitWindowSize(w, w);
    // 设置窗口出现的位置
    glutInitWindowPosition((cx - w) / 2,(cy - w) / 2);
	return w;
}

void scale_mouse_wheel(int button, int state, int x, int y, GLdouble *scale, GLdouble delta, GLdouble low, GLdouble high)
{
    if (state == GLUT_UP) {
        if (button == 3) {
            if (*scale < high) {
                *scale += delta;
            }
        } else if (button == 4) {
            if (*scale > low) {
                *scale -= delta;
            }
        }
        glutPostRedisplay();
    }
}

void self_adapt(GLsizei w, GLsizei h, GLdouble factor, GLdouble distance)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w > h)
        glOrtho(-factor *(GLdouble)(w) / h, factor *(GLdouble)(w) / h, -factor, factor, -distance, distance);
    else
        glOrtho(-factor, factor, -factor *(GLdouble)(h) / w, factor *(GLdouble)(h) / w, -distance, distance);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
#endif // DISPLAY_H
