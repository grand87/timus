#include <utils.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

// Position this line where user code will be pasted.
/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
bool check(int V, int* res, vector<int> adj[]) {
    bool flag = true;
    for (int i = 0; i < V && flag; i++) {
        int n = adj[res[i]].size();
        for (auto j : adj[res[i]]) {
            for (int k = i + 1; k < V; k++) {
                if (res[k] == j)
                    n--;
            }
        }
        if (n != 0)
            flag = false;
    }
    if (flag == false)
        return 0;
    return 1;
}

struct GraphTrackingInfo {
    enum class VertexStage : char { Closed = 0, Opened = 1, Done = 2 };

    vector<VertexStage> visited;
    vector<int> sorted;

    GraphTrackingInfo(int n) : visited(n) {
        sorted.reserve(n);
    }
};

void onVertexEnter(int vertexIndex, vector<int>* adj, GraphTrackingInfo* userData);
void onVertexExit(int vertexIndex, vector<int>* adj, GraphTrackingInfo* userData);

void dfs(int vertex, vector<int>* adj, GraphTrackingInfo* userData) {
    // need to evaluate only on opened verticies
    if (userData->visited[vertex] != GraphTrackingInfo::VertexStage::Closed)
        return;

    // mark vertex as opened
    userData->visited[vertex] = GraphTrackingInfo::VertexStage::Opened;

    onVertexEnter(vertex, adj, userData);
    // evaluate all adjecent verticies
    for (auto adjVert : adj[vertex]) {
        dfs(adjVert, adj, userData);
    }

    // mark vertex as closed
    onVertexExit(vertex, adj, userData);

    userData->visited[vertex] = GraphTrackingInfo::VertexStage::Done;
}

void onVertexEnter(int vertexIndex, vector<int>* adj, GraphTrackingInfo* userData) {
}

void onVertexExit(int vertexIndex, vector<int>* adj, GraphTrackingInfo* userData) {
    cout << "Processed vertex " << vertexIndex << endl;
    userData->sorted.push_back(vertexIndex);
}

/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
 *   N: number of vertices
 *   adj[]: input graph
 *   NOTE: You must return dynamically allocated array
 */
int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    GraphTrackingInfo trackInfo(V);

    for (int i = 0; i < V; i++) {
        dfs(i, adj, &trackInfo);
    }

    int* result = new int[V];
    memcpy(result, &trackInfo.sorted[0], V * sizeof(int));
    reverse(result, result + V);

    return result;
}

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<int>* ptrToVector = &adj[0];
        vector<int>* ptrToVector1 = &adj[1];
        vector<int>* ptrToVector2 = &adj[2];
        int* res = topoSort(N, ptrToVector);

        cout << check(N, res, &adj[0]) << endl;
    }

    return 0;
}