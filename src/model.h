#include<vector>

class Model
{
	public:
		Model();

		//Setters
		void setVerts(std::vector<std::vector<float> > set);
		void setNorms(std::vector<std::vector<float> > set);
		void setTex(std::vector<std::vector<float> > set);
		void setFaces(std::vector<std::vector<int> > set);

		//Getters
		std::vector<std::vector<float> > getVerts();
		std::vector<std::vector<float> > getNorms();
		std::vector<std::vector<float> > getTex();
		std::vector<std::vector<int> > getFaces();
		
		bool hasTex;
		bool hasNorm;
		float x, y, z;
	private:
		std::vector<std::vector<float> > verts;
		std::vector<std::vector<float> > norms;
		std::vector<std::vector<float> > tex;
		std::vector<std::vector<int> > faces;
};
