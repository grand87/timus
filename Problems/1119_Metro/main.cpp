#include <iostream>
#include <math.h>

using namespace std;

#define MAX_GRID_SIZE 1001

//direction are right, up, right-up 
#define MAX_NEIGHBORS 3
#define MAX_NODES (MAX_GRID_SIZE + 1) * (MAX_GRID_SIZE + 1)
#define INF 99999999999.99;

struct node
{
    node(unsigned int aX = -1, unsigned int aY = -1) : x(aX), y(aY)
    {

    }

    node(const node& aNode) : x(aNode.x), y(aNode.y)
    {

    }

    unsigned int x;
    unsigned int y;
};

typedef long double Distance;

const node offsets[] = { node(1,0), node(0,1), node(1,1) };

node neighbors[MAX_NEIGHBORS];
Distance dist[MAX_NODES];
bool diagonals[MAX_GRID_SIZE][MAX_GRID_SIZE];
long double distances[MAX_GRID_SIZE][MAX_GRID_SIZE];

Distance diagonalSize = sqrt(100 * 100 + 100 * 100);

unsigned int gridX = 0, gridY = 0, diagonalsCount = 0;

unsigned int getNeighbors(const node& aNode)
{
    unsigned int count = 0;
    unsigned int max_n = MAX_NEIGHBORS;

    for (unsigned short i = 0; i < max_n; ++i)
    {
        const unsigned short nX = aNode.x + offsets[i].x;
        if (nX < 0 || nX > gridX)
        {
            neighbors[i] = node(-1, -1);
            //diagonal in this case also imposible - if there is no cells above
            max_n = 2;
            continue;
        }
        const unsigned short nY = aNode.y + offsets[i].y;
        if (nY < 0 || nY > gridY)
        {
            neighbors[i] = node(-1, -1);
            //diagonal in this case also imposible - if there is no cells above
            break;
        }

        if (i < 2)
        {
            neighbors[i] = node(nX, nY);
            count++;
        }
        else
            if (diagonals[nX][nY])
            {
                neighbors[i] = node(nX, nY);
                count++;
            }
            else
                neighbors[i] = node(-1, -1);
    }
    return count;
}

node getByIndex(unsigned int id)
{
    return node(id % gridX, id / gridX);
}

template <typename T> struct Queue
{
    Queue() : _top(0)
    {

    }

    void push(const T& t)
    {
        buffer[_top] = t;
        ++_top;
    }
    
    void pop()
    {
        --_top;
    }

    const T* top()
    {
        return get(_top - 1);
    }

    unsigned int size() const
    {
        return _top;
    }

    const T* get(unsigned int index)
    {
        return &buffer[index];
    }

    T buffer[MAX_NODES];
    unsigned int _top;
};

Queue<unsigned int> vertexesToProcess;

Distance deikstra(unsigned int target, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
        dist[i] = INF;
    Distance md = INF;
    Distance temp;

    dist[0] = 0;
    vertexesToProcess.push(0);
    
    while (vertexesToProcess.size() > 0)
    {
        const unsigned int activeVertexID = *vertexesToProcess.top();
        vertexesToProcess.pop();

        //get all neighbors (max 3)
        node active_node(activeVertexID % gridX, activeVertexID / gridX);
        unsigned int nc = getNeighbors(active_node);

        //updates weights for all neighbors
        for (unsigned short i = 0; i < nc; ++i)
        {
            const node& neighbor = neighbors[i];
            const unsigned int nId = neighbor.y * gridX + neighbor.x;

            if (i == 2) //only diagonal could be 3rd
                temp = dist[activeVertexID] + diagonalSize;
            else
                temp = dist[activeVertexID] + 1;

            if ((activeVertexID == 0) || (dist[nId] > temp && md > temp))
            {
                dist[nId] = temp;

                if (nId != target)
                    vertexesToProcess.push(nId);
                else
                    md = dist[nId];
            }
        }
    }
    return dist[target];
}

long double min(long double val1, long double val2, long double val3)
{
    if (val1 <= val2 && val1 <= val3)
        return val1;
    if (val2 <= val1 && val2 <= val3)
        return val2;
    if (val3 <= val1 && val3 <= val2)
        return val3;
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
            diagonals[i][j] = false;
        }

    for (unsigned int i = 0; i < diagonalsCount; ++i)
    {
        unsigned x, y;
        cin >> x >> y;
        diagonals[x][y] = true;
    }

    distances[0][0] = 0;

    for (unsigned int i = 0; i < gridX; ++i)
        for (unsigned int j = 0; j < gridY; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            long double d1 = i == 0 ? distances[i][j - 1] + 100 : distances[i - 1][j] + 100; //left
            long double d2 = j == 0 ? distances[i - 1][j] + 100 : distances[i][j - 1] + 100; //bottom
            long double d3 = diagonals[i][j] ? distances[i - 1][j - 1] + diagonalSize : INF; //left-bottom

            distances[i][j] = min(d1, d2, d3);
        }

    Distance length = distances[gridX - 1][gridY - 1];

    cout << round(length);
}