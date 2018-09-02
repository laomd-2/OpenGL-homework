#include "stdafx.h"
#include <cmath>
#include <GL/glut.h>
#include "../common/display.h"
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

using namespace std;

struct Point
{
public:
	Point(GLfloat xx=0, GLfloat yy=0) {
		x = xx;
		y = yy;
	}
	
	GLfloat x, y;
};

Point points[4];
size_t num_points = 0;
GLfloat win_size;

void drawLine() {
	// 每相邻连个点画一条直线
	for (int i = 0; i < 3; i++) {
		glBegin(GL_LINES);
		glVertex2f(points[i].x, points[i].y);
		glVertex2f(points[i + 1].x, points[i + 1].y);
		glEnd();
	}
}

void drawBezier() {
	for (GLfloat t = 0; t <= 1.0; t += 0.001) {
		// 贝塞尔曲线公式
		GLfloat x = points[0].x*pow(1.0f - t, 3) + 3 * points[1].x*t*pow(1.0f - t, 2) + 3 * points[2].x*t*t*(1.0f - t) + points[3].x*pow(t, 3);
		GLfloat y = points[0].y*pow(1.0f - t, 3) + 3 * points[1].y*t*pow(1.0f - t, 2) + 3 * points[2].y*t*t*(1.0f - t) + points[3].y*pow(t, 3);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
	}
}

void display() {
	glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		// 四个点都选好了，画直线和曲线
		if (num_points == 4) {
			// 清除掉屏幕上的点
			glClear(GL_COLOR_BUFFER_BIT);
			// 线是白色的
			glColor3f(255.0f, 255.0f, 255.0f);
			glPointSize(1.0);
			drawLine();
			drawBezier();
			// 清空数组
			num_points = 0;
		}
		else
		{
			// 刚刚画完曲线，初始化
			if (num_points == 0)
			{
				glClear(GL_COLOR_BUFFER_BIT);
				glColor3f(1.0f, 0, 0);
				glPointSize(5.0);
			}

			// 画点
			glBegin(GL_POINTS);
			glVertex2i(x, win_size - y);
			glEnd();
			points[num_points++] = Point(x, win_size - y);
		}

		glFlush();
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	win_size = alignCenter(0.8);
	glutCreateWindow("Bezier-curve");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0, win_size, 0.0, win_size);

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}