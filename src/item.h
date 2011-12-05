#ifndef ITEM
#define ITEM
#include<vector>

class Item
{
	public:
		Item(float xi, float yi, float zi, int type);
	private:
		std::vector<std::vector<float> > verts;
		std::vector<std::vector<float> > norms;
		std::vector<std::vector<float> > texts;
		std::vector<std::vector<int> > faces;
		std::vector<std::vector<int> > normF;
		std::vector<std::vector<int> > textF;
		float color[3];
		float x, y, z;
}
#endif
