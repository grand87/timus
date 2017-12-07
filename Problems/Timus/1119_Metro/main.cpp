#include <iostream>
#define MAX_SIZE 1000

unsigned int sizeX, sizeY;

unsigned short graph[MAX_SIZE][MAX_SIZE];

struct vertex
{
	vertex(unsigned int _x, unsigned int _y) : x(_x), y(_y)
	{

	}
	unsigned int x;
	unsigned int y;
};

vertex kVerts[100];

vertex getForIndex(unsigned int index)
{
	// convert index into x,y where 0 - left bottom, max - right upper
	unsigned int row = index / sizeX;
	unsigned int col = index % sizeX;
	return vertex(col, row);
}

vertex getSosedX(const vertex &source)
{
	return vertex(source.x + 1, source.y);
}

vertex getSosedY(const vertex &source)
{
	return vertex(source.x, source.y + 1);
}

vertex getSosedW(const vertex &source)
{
	
	return vertex(source.x, source.y + 1);
}


unsigned int deikstra()
{
	const unsigned int vertexesCount = (sizeX + 1) * (sizeY + 1);
	unsigned int dist[(MAX_SIZE + 1) * (MAX_SIZE + 1)];
	bool visited[(MAX_SIZE + 1) * (MAX_SIZE + 1)];

	for (unsigned int i = 0; i < vertexesCount; ++i)
		dist[i] = -1;

	unsigned int minDist = 0;
	dist[0] = 0;

	do
	{


	} while (minDist != -1)
}


int main()
{
    bool valsExists = false;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    std::cin >> sizeX >> sizeY;

	/* init graph as square based grid for example 2x2 - means 4 vertexes

	Y---Z
	|   |
	|   |
	X---W

	will be represented as graph


	for (unsigned int j = 0; j < sizeY; ++j);

		for (unsigned int i = 0; i < sizeX; ++i)
		{

		}
		*/

	std::cin >> sizeK;
	for (unsigned int k = 0; k < sizeK; ++k)
		std::cin >> kVerts[k].y >> kVerts[k].x;


    
}
