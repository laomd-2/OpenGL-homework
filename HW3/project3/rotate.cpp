#include "display.h"

int year = 0, day = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glColor3f(1, 1, 1);             //线条为白色
    glutWireSphere(1, 20, 16);      //绘制太阳

    glRotated(year, 0, 1, 0);       //公转-沿y轴旋转
    glTranslatef(2, 0, 0);          //行星沿x轴正方向移动2个单位
    glRotated(day, 0, 1, 0);        //自转-沿y轴旋转
    glutWireSphere(0.2, 10, 8);     //绘制行星

    glPopMatrix();
    glutSwapBuffers();
    glFlush();   //刷新窗口
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60, (GLfloat)w / h, 1.0, 20);   // w/h，确保窗口尺寸变化时图形不变形

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'd':   // 正方向自转
            day = (day + 10) % 360;
            break;
        case 'D':   // 反方向自转
            day = (day - 10) % 360;
            break;
        case 'y':   // 正方向公转
            year = (year + 5) % 360;
            break;
        case 'Y':   // 反方向公转
            year = (year - 5) % 360;
            break;
        default:    // 忽略其他输入
            return;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    alignCenter(0.7);
    glutCreateWindow("project2");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}