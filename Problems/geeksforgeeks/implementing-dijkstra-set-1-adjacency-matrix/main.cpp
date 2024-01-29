#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <utils.h>

using namespace std;

void dijkstra(vector<vector<int>> graph, int src, int V) {

    vector<int> opened(V);
    vector<int> distances(V, INT_MAX);

    distances[src] = 0;


    //start BFS from the src pos
    queue<int> verts;
    verts.push(src);

    while (!verts.empty()) {
        const int currentV = verts.front();
        verts.pop();
        opened[currentV] = true;

        //evaluate each adjecent vert
        for (int i = 0; i < V; i++) {
            if (graph[currentV][i] > 0) {
                const int distance = graph[currentV][i];
                //there is a direct connection between 2 verticies
                if (distances[i] > distances[currentV] + distance) {
                    distances[i] = distances[currentV] + distance;
                    verts.push(i);
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << distances[i] << " ";
    }
}

int main()
{
#ifdef LOCAL_TEST
    fstream inputData("input.txt");
    cin.set_rdbuf(inputData.rdbuf());
#endif

    int t;
    int V;
    cin >> t;
    while (t--) {
        cin >> V;

        vector<vector<int>> g(V);

        for (int i = 0; i<V; i++) {
            vector<int> temp(V);
            g[i] = temp;
        }

        for (int i = 0; i<V; i++)
        {
            for (int j = 0; j<V; j++)
            {
                cin >> g[i][j];
            }
        }

        int s;
        cin >> s;

        dijkstra(g, s, V);
        cout << endl;
    }
    return 0;
}