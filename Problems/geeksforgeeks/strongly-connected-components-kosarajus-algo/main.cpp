#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <utils.h>

using namespace std;

void topologicalSort(int v, vector<int> adj[], vector<int> &visited, stack<int> &order) {
    visited[v] = 1;

    for (int i = 0; i < adj[v].size(); i++) {
        const int connectedVert = adj[v][i];
        if (visited[connectedVert] == 0) {
            topologicalSort(connectedVert, adj, visited, order);
        }
    }
    order.push(v);
}

void dfs(int v, vector<int> adj[], vector<int> &visited) {
    visited[v] = 1;

    for (int i = 0; i < adj[v].size(); i++) {
        const int connectedVert = adj[v][i];
        if (visited[connectedVert] == 0) {
            dfs(connectedVert, adj, visited);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> order;

    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            topologicalSort(i, adj, visited, order);
        }
    }

    //transpose graph
    vector<int> *transAdj = new vector<int>[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            transAdj[adj[i][j]].push_back(i);
            //cout << "From " << adj[i][j] << " to " << i << endl;
        }
    }

    int count = 0;
    fill(visited.begin(), visited.end(), 0);

    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (visited[v] == 0) {
            count++;
            dfs(v, transAdj, visited);
        }
    }

    delete[] transAdj;
    return count;
}

int main()
{
#ifdef LOCAL_TEST
    fstream inputData("input.txt");
    cin.set_rdbuf(inputData.rdbuf());
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int>* adj = new vector<int>[a + 1];
        for (int i = 0; i<b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
        delete[] adj;
    }
    return 0;
}