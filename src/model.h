#include<vector>

class Model
{
	public:
		Model();

		//Setters
		void setVerts(std::vector<std::vector<float> > set);
		void setNorms(std::vector<std::vector<float> > set);
		void setTex(std::vector<std::vector<float> > set);

		//Getters
		std::vector<std::vector<float> > getVerts();
		std::vector<std::vector<float> > getNorms();
		std::vector<std::vector<float> > getTex();

		bool hasTex;
		bool hasNorm;

	private:
		std::vector<std::vector<float> > verts;
		std::vector<std::vector<float> > norms;
		std::vector<std::vector<float> > tex;

};
