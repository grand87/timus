#include <iostream>
#include <math.h>

using namespace std;

#define MAX_GRID_SIZE 1000

//direction are right, up, right-up 
#define MAX_NEIGHBORS 3

#define MAX_NODES (MAX_GRID_SIZE + 1) * (MAX_GRID_SIZE + 1)

struct node
{
    node(unsigned short aX = -1, unsigned short aY = -1) : x(aX), y(aY)
    {

    }

    node(const node& aNode) : x(aNode.x), y(aNode.y)
    {

    }

    unsigned short x;
    unsigned short y;
};

node neighbors[MAX_NEIGHBORS];
double dist[MAX_NODES];
bool visited[MAX_NODES];
bool diagonals[MAX_GRID_SIZE][MAX_GRID_SIZE];

float diagonalSize = sqrt(100 * 100 + 100 * 100);

unsigned short gridX = 0, gridY = 0, diagonalsCount = 0;

void getNeighbors(const node& aNode)
{
    const node offsets[] = { node(0,1), node(1,0), node(1,1), node(0,-1), node(-1,0), node(1,-1), node(-1,-1), node(-1,1) };

    for (unsigned short i = 0; i < MAX_NEIGHBORS; ++i)
    {
        const unsigned short nX = aNode.x + offsets[i].x;
        const unsigned short nY = aNode.y + offsets[i].y;

        if (nX >= 0 && nX < gridX && nY >= 0 && nY < gridY)
        {
            if (i < 2)
                neighbors[i] = node(nX, nY);
            else
                if (diagonals[nX][nY])
                    neighbors[i] = node(nX, nY);
                else
                    neighbors[i] = node(-1, -1);
        }
        else
            neighbors[i] = node(-1, -1);
    }
}

node getByIndex(unsigned short id)
{
    return node(id % gridX, id / gridX);
}

#define INF 99999999999.99;

double deikstra(unsigned int target, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    double minDist;
    unsigned int activeVertexID;

    dist[0] = 0;

    do
    {
        minDist = INF;
        activeVertexID = -1;

        //improve to queue
        for (unsigned int i = 0; i < size; ++i)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                activeVertexID = i;
            }
        }

        if (activeVertexID < -1)
        {
            visited[activeVertexID] = true;

            //updates weights for all neighbors
            node active = getByIndex(activeVertexID);
            getNeighbors(active);

            for (unsigned short i = 0; i < MAX_NEIGHBORS; ++i)
            {
                if (neighbors[i].x < (unsigned short)-1)
                {
                    unsigned int nId = neighbors[i].y * gridX + neighbors[i].x;
                    //improve with diagonals

                    double temp;
                    if (diagonals[neighbors[i].x][neighbors[i].y])
                        temp = minDist + diagonalSize;
                    else
                        temp = minDist + 100;
                    if (temp < dist[nId])
                        dist[nId] = temp;
                }
            }
        }

    } while (activeVertexID < -1);

    return dist[target];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> gridX >> gridY;
    ++gridX;
    ++gridY;

    cin >> diagonalsCount;

    for (unsigned int i = 0; i < gridX; ++i)
        for (unsigned int j = 0; j < gridY; ++j)
        {
            diagonals[i][j] = 0;
        }

    for (unsigned int i = 0; i < diagonalsCount; ++i)
    {
        unsigned x, y;
        cin >> x >> y;
        diagonals[x][y] = 1;
    }

    const unsigned int vertexes = gridX * gridY;

    //init grid vertexes
    double length = deikstra(vertexes - 1, vertexes);

    cout << ceil(length);
}