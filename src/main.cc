#include"model.h"
#include<GL/glew.h>
#include<iostream>

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
	float vert_array[8][3] = {{-0.5, 0.5, -0.5}, 	//1
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

	vector<vector<float> > verts;
	vector<vector<int> > faces;
	
	for(int i = 0; i < 8; i++)
	{
		vector<float> temp;
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
	renderTest();
	glTranslatef(0, 0, -2);
	renderTri();	
	glPopMatrix();	
	glFlush();
}

void renderTest()
{
	vector<vector<float> > verts = mdl.getVerts();
	vector<vector<int> > faces = mdl.getFaces();
	glTranslatef(mdl.x, mdl.y, mdl.z);
	glColor3f(0.0f, 0.5f, 0.5f);
	for(int i = 0; i < faces.size(); i++)
	{
		for(int j = 0; j < faces[i].size(); j++)
		{
			int vert = faces[i][j] - 1;
			cout << i << " " << j << " " << vert << " there\n";
			glBegin(GL_QUADS);
				glVertex3f(verts[vert][0],
						   verts[vert][1],
						   verts[vert][2]);
			glEnd();
			cout << "     " << verts[vert][0] << verts[vert][1] << verts[vert][2] << endl;
		}
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
	
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();
}
