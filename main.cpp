
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);

    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);

    }
    glEnd();
}
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    DrawCircle(0.5, 0.5,0.25,100);
	glFlush();
}


void Initialize() {
	glClearColor(0.0, 128.0/255.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650, 350);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Bangladesh");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
