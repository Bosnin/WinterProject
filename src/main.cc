#include"model.h"
#include<GL/glew.h>

#ifdef __APPLE__
#	include <GLUT/glut.h>
#else
#	include <GL/glut.h>
#endif

void display();
void reshape(int width, int height);
void renderTri();

int main(int argc, char** argv)
{
	Model mdl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Winter Project");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
}

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	renderTri();	
	glPopMatrix();	
	glFlush();
}

void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void renderTri()
{
	glBegin(GL_TRIANGLES);
	
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();
}
