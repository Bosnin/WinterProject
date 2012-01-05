/*
	Mirza Prasovic 
	Winter Project using OpenGL to practice use and 
	try some cool stuff
	1/5/2012
*/

#include<GL/glew.h>
#include<iostream>
#include"model.h"

#ifdef __APPLE__
#	include <GLUT/glut.h>
#else
#	include <GL/glut.h>
#endif

using namespace std;

void display();
void reshape(int width, int height);
void renderTri();
void renderTest();
void init();
Model loadTest();
Model mdl;

int main(int argc, char** argv)
{	
	mdl = loadTest();
	mdl.z = -3.0f;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Winter Project");
	
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
}

void init()
{
	glEnable(GL_DEPTH_TEST);
}

Model loadTest()
{
	Model ret;
	GLfloat vert_array[8][3] = {{-0.5, 0.5, -0.5}, 	//1
								{-0.5, -0.5, -0.5},	//2
								{0.5, -0.5, -0.5}, 	//3
								{0.5, 0.5, -0.5},  	//4
								{-0.5, 0.5, 0.5},  	//5
								{-0.5, -0.5, 0.5}, 	//6
								{0.5, -0.5, 0.5},  	//7
								{0.5, 0.5, 0.5}};   //8
	int face_array[6][4] = {{1, 2, 3, 4},
						  {5, 6, 7, 8},
						  {5, 6, 2, 1},
						  {4, 3, 7, 8},
						  {5, 1, 4, 8},
						  {7, 3, 2, 6}};

	vector<vector<GLfloat> > verts;
	vector<vector<int> > faces;
	
	for(int i = 0; i < 8; i++)
	{
		vector<GLfloat> temp;
		for(int j = 0; j < 3; j++)
		{
			temp.push_back(vert_array[i][j]);
		}
		verts.push_back(temp);
	}

	for(int i = 0; i < 6; i++)
	{
		vector<int> temp;
		for(int j = 0; j < 4; j++)
		{
			temp.push_back(face_array[i][j]);
		}
		faces.push_back(temp);
	}

	ret.setVerts(verts);
	ret.setFaces(faces);
	return ret;
}

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	//TEST	
	glColor3f(1, 1, 1);
	renderTest();
	glPopMatrix();	
	glFlush();
}

void renderTest()
{
	vector<vector<GLfloat> > verts = mdl.getVerts();
	vector<vector<int> > faces = mdl.getFaces();
	glTranslatef(mdl.x, mdl.y, mdl.z);
	GLfloat colors[3][3] = {{1.0f, 0.0f, 0.0f},
							{0.0f, 1.0f, 0.0f},
							{0.0f, 0.0f, 1.0f}};
	for(int i = 0; i < faces.size(); i++)
	{
		cout << "Face: " << i;
		glBegin(GL_QUADS);
		for(int j = 0; j < faces[i].size(); j++)
		{
			int vert = faces[i][j] - 1;
			cout << " vert num: " << vert << "\n";
			cout << "x " << verts[vert][0] << " y " << verts[vert][1] << " z " << verts[vert][2] << "\n";;
			int c = vert % 3;
			glColor3f(colors[c][0], colors[c][1], colors[c][2]);	
			glVertex3f(verts[vert][0],
					   verts[vert][1],
					   verts[vert][2]);

		}
		glEnd();
	}

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
	float x = 1.25f;
	float y = -1.25f;
	float z = 0.0f;
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -3);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	
	glVertex3f(x, y, z);
	glVertex3f(y, y, z);
	glVertex3f(z, x, z);

	glEnd();
}
