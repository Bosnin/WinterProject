#include "model.h"

using namespace std;

Model::Model()
{
	hasTex = false;
	hasNorm = false;
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}


void Model::setVerts(vector<vector<GLfloat> > set)
{
	verts = set;
}


void Model::setNorms(vector<vector<GLfloat> > set)
{
	norms = set;
}

void Model::setTex(vector<vector<GLfloat> > set)
{
	tex = set;
}

void Model::setFaces(vector<vector<int> > set)
{
	faces = set;
}

vector<vector<GLfloat> > Model::getVerts()
{
	return verts;
}

vector<vector<GLfloat> > Model::getNorms()
{
	return verts;
}

vector<vector<GLfloat> > Model::getTex()
{
	return verts;
}

vector<vector<int> > Model::getFaces()
{
	return faces;
}
