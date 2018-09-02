#include <GL/glut.h>
#include "display.h"

GLdouble scale = 0.5;

void init();
void myMouse(int button, int state, int x, int y);
void display();
void reshape(int w, int h);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    alignCenter(0.6);
    glutCreateWindow(argv[0]);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(myMouse);

    glutMainLoop();
    return 0;
}

void init()
{
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat ls_pos[] = {1.0, 1.0, 1.0, 0.0};
    // 白色光
    GLfloat ls_color[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat lm_ambient[] = {0.2 , 0.2 , 0.2 , 1.0};

    // 初始化 material property
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_BACK, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // 初始化light source
    glLightfv(GL_LIGHT0, GL_POSITION, ls_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ls_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ls_color);
    // 初始化lighting model
    // 设置光的环境强度
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT , lm_ambient);

    // depth buffer
    glEnable(GL_DEPTH_TEST);
}

void myMouse(int button, int state, int x, int y)
{
    scale_mouse_wheel(button, state, x, y, &scale, 0.05, 0.2, 0.9);
}

void display()
{
    // RGB模式, 把所有像素的深度值设置为最大值
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutSolidTeapot(scale);
    glFlush();
    glutSwapBuffers(); //实现双缓存
}

void reshape(int w, int h)
{
    self_adapt(w, h, 1.5, 10.0);
}
