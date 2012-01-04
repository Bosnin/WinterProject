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


void Model::setVerts(vector<vector<float> > set)
{
	verts = set;
}


void Model::setNorms(vector<vector<float> > set)
{
	norms = set;
}

void Model::setTex(vector<vector<float> > set)
{
	tex = set;
}

void Model::setFaces(vector<vector<int> > set)
{
	faces = set;
}

vector<vector<float> > Model::getVerts()
{
	return verts;
}

vector<vector<float> > Model::getNorms()
{
	return verts;
}

vector<vector<float> > Model::getTex()
{
	return verts;
}

vector<vector<int> > Model::getFaces()
{
	return faces;
}
