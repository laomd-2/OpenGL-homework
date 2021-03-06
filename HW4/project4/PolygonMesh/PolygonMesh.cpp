// PolygonMesh.cpp: 定义控制台应用程序的入口点。
//
// bezier.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cmath>
#include "../common/display.h"
#include "vector2.h"
#include "io.h"
using namespace std;

#define str(a) #a

bool btn_down = 0; //鼠标按钮的状态
Vector2 rotate_v, last_pos;
float ty = 0.0f;

enum ShowMode {
	Flat, WireFrame, Flatlines
}show_mode;
const char* mode_names[] = {str(WireFrame), str(Flatlines), str(Flat)};

//  键盘交互
void special(int key, int x, int y) {
	if (key >= GLUT_KEY_F1 && key <= GLUT_KEY_F3)
	{
		int tmp = key - GLUT_KEY_F1;
		if (index != tmp)
		{
			index = tmp;
			readCurFile();
		}		
	}
	else
	{
		switch (key)
		{
		case GLUT_KEY_F4:
			show_mode = (ShowMode)((show_mode + 1) % 3);
			cout << "change show mode to " << mode_names[show_mode] << endl;
			break;
		case GLUT_KEY_UP:
			ty += 0.01;
			break;
		case GLUT_KEY_DOWN:
			ty -= 0.01;
			break;
		default:
			break;
		}
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	btn_down = state == GLUT_DOWN;
	if (btn_down)	// 鼠标按钮实现平移和旋转
	{
		last_pos.x = x;
		last_pos.y = y;
	}
	glutPostRedisplay();
}

void motion(int x, int y) {
	if (btn_down) {
		//x对应y是因为对应的是法向量
		rotate_v.y += x - last_pos.x;
		glutPostRedisplay();
		last_pos.x = x;
		rotate_v.x += y - last_pos.y;
		glutPostRedisplay();
		last_pos.y = y;
	}
}

// 当窗体改变大小的时候
void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h)
		glOrtho(-(GLdouble)(w) / h, (GLdouble)(w) / h, -1.0, 1.0, -100.0, 100.0);
	else
		glOrtho(-1.0, 1.0, -(GLdouble)(h) / w, (GLdouble)(h) / w, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_v.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotate_v.y, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, ty);

	if (index == 2)
	{
		glScalef(0.01f, 0.01f, 0.01f); // 缩放
	}
	else
	{
		glScalef(1, 1, 1); // 缩放
	}

	switch (show_mode)
	{
	case Flat:
		glCallList(showFaceList);
		break;
	case WireFrame:
		glCallList(showWireList);
		break;
	case Flatlines:
		glCallList(showFaceList);
		glCallList(showWireList);
		break;
	default:
		break;
	}
	glutSwapBuffers(); //实现双缓存
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // 使用双缓存
	alignCenter(0.9);
	glutCreateWindow("Mesh Viewer");

	readCurFile();
	
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}

