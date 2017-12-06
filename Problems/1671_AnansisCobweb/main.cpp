#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int MAX_N = 100000;
typedef list<int> connectedVertexes;

void evaluateConnected(connectedVertexes *graph, int startVertex, bool* vertexIsVisited)
{
    int activeVertex = startVertex;
    list<int> vertexesToVisit;
    vertexesToVisit.push_back(activeVertex);
    while (vertexesToVisit.size() > 0)
    {
        activeVertex = vertexesToVisit.front();
        vertexesToVisit.pop_front();
        vertexIsVisited[activeVertex] = true;

        for (list<int>::iterator it = graph[activeVertex].begin(); it != graph[activeVertex].end(); ++it)
        {
            if (*it != 0 && !vertexIsVisited[*it])
                vertexesToVisit.push_back(*it);
        }
    }
}

//located first unvisited vertex
int getUnvisited(const bool* vertexIsVisited, int count)
{
    for (int i = 1; i <= count; i++)
    {
        if (!vertexIsVisited[i])
            return i;
    }
    return -1;
}

int getConnComponents(int vertexCount, connectedVertexes *graph)
{
    int components = 0;

    bool vertexIsVisited[MAX_N + 1];
    memset(vertexIsVisited, 0, (MAX_N + 1) * sizeof vertexIsVisited[0]);

    int toVisit = getUnvisited(vertexIsVisited, vertexCount);
    while (toVisit != -1)
    {
        evaluateConnected(graph, toVisit, vertexIsVisited);
        components++;
        toVisit = getUnvisited(vertexIsVisited, vertexCount);
    }

    return components;
}

struct edge
{
    int first;
    int second;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    cin >> n >> m;

    edge edges[MAX_N + 1];
    connectedVertexes *graph = new connectedVertexes[MAX_N + 1];

    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        edges[i + 1].first = v1;
        edges[i + 1].second = v2;
    }

    //generate connectivity components

    int edgesToRemove;
    cin >> edgesToRemove;

    for (int i = 0; i < edgesToRemove; ++i)
    {
        //remove some edge
        int edgeIndex;
        cin >> edgeIndex;

        const edge e = edges[edgeIndex];

        for (list<int>::iterator it = graph[e.first].begin(); it != graph[e.first].end(); ++it)
        {
            if (*it == e.second)
            {
                graph[e.first].erase(it);
                break;
            }
        }

        for (list<int>::iterator it = graph[e.second].begin(); it != graph[e.second].end(); ++it)
        {
            if (*it == e.first)
            {
                graph[e.second].erase(it);
                break;
            }
        }

        int components = getConnComponents(n, graph);

        std::cout << components << " ";
    }
}