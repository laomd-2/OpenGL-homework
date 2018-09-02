#include <GL/glut.h>
#include "display.h"

void drawRectangle() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-0.5, -0.5, 0.5, 0.5);
    glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	// 窗口出现位置居中对齐
	alignCenter(0.6);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("The first openGL program");

	glutDisplayFunc(drawRectangle);
	
	glutMainLoop();

	return 0;
}
