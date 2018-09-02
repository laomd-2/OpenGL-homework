#include <GL/glut.h>
#include "display.h"

void drawCube()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 进行视图变换，参数分别为摄像机位置(-0.85, 0.25, 1.5)，摄像机朝向(0.0, 0.0, 0.0)即原点，朝上的方向向量(1, 1.5, 0) 
    gluLookAt(-0.85, 0.25, 1.5, 0, 0, 0, 1, 1.5, 0);

    // 绘制实心立方体
    glColor3f(0, 1, 0);	// 绿色
    glutSolidCube(1);

    // 绘制线框立方体
    glColor3f(0, 0, 0);	// 黑色
    glLineWidth(2.0f);	// 设置边的像素宽，默认为1.0f
    glutWireCube(1);

    glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);  // 调整视图窗口大小
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65, 1, 0, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    alignCenter(0.6);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("The perspective projection");

    glutDisplayFunc(drawCube);
    glutReshapeFunc(reshape);

    glutMainLoop();

	return 0;
}
