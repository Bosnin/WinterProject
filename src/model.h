#include<vector>

#ifdef __APPLE__
#	include <GLUT/glut.h>
#else
#	include <GL/glut.h>
#endif
class Model
{
	public:
		Model();

		//Setters
		void setVerts(std::vector<std::vector<GLfloat> > set);
		void setNorms(std::vector<std::vector<GLfloat> > set);
		void setTex(std::vector<std::vector<GLfloat> > set);
		void setFaces(std::vector<std::vector<int> > set);

		//Getters
		std::vector<std::vector<GLfloat> > getVerts();
		std::vector<std::vector<GLfloat> > getNorms();
		std::vector<std::vector<GLfloat> > getTex();
		std::vector<std::vector<int> > getFaces();
		
		bool hasTex;
		bool hasNorm;
		GLfloat x, y, z;
	private:
		std::vector<std::vector<GLfloat> > verts;
		std::vector<std::vector<GLfloat> > norms;
		std::vector<std::vector<GLfloat> > tex;
		std::vector<std::vector<int> > faces;
};
