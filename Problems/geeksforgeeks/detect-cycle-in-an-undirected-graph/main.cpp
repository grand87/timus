#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

bool isCyclic(vector<int> adj[], int V);

// Position this line where user code will be pasted.
int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;

    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int>* adj = new vector<int>[V];

        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V) << endl;

        delete[] adj;
    }

    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
 *   V: number of vertices
 *   adj[]: representation of graph
 */

enum class VertexState : char { None = 0, Open, Done };

struct DFSMeta {
    typedef bool (*OnVertexEnter)(int v, vector<int> adj[], DFSMeta* meta);
    typedef bool (*OnVertexExit)(int v, vector<int> adj[], DFSMeta* meta);
    typedef bool (*OnEdge)(int src, int dst, vector<int> adj[], DFSMeta* meta, int color);

    OnVertexEnter onVertexEnter;
    OnVertexExit onVertexExit;
    OnEdge onEdge;

    vector<vector<int>> edges;

    vector<VertexState> states;

    bool hasCycle;

    vector<int> parent;

    DFSMeta(int n) : edges(n), states(n), parent(n) {
        onVertexEnter = nullptr;
        onVertexExit = nullptr;
        onEdge = nullptr;
        hasCycle = false;

        for (int i = 0; i < n; i++)
            edges[i].resize(n);
    };
};

void dfs(int v, vector<int> adj[], DFSMeta& meta, int color) {
    meta.states[v] = VertexState::Open;

    if (meta.onVertexEnter != nullptr)
        meta.onVertexEnter(v, adj, &meta);

    for (size_t i = 0; i < adj[v].size(); i++) {
        const int connectedVertex = adj[v][i];
       
        if (meta.states[connectedVertex] == VertexState::None) {
            meta.parent[connectedVertex] = v;
            meta.onEdge(v, connectedVertex, adj, &meta, color);
            dfs(connectedVertex, adj, meta, color + 1);
        } else if (meta.states[connectedVertex] == VertexState::Open) {
            meta.onEdge(v, connectedVertex, adj, &meta, color);
        }
    }

    meta.states[v] = VertexState::Done;

    if (meta.onVertexExit != nullptr)
        meta.onVertexExit(v, adj, &meta);
}

bool OnEdgeHandler(int src, int dst, vector<int> adj[], DFSMeta* meta, int color) {
    if (src == dst) {
        //self-loop case
        meta->hasCycle = true;
        return true;
    } else if (meta->edges[src][dst] == 0) {
        // edge visited first time
        meta->edges[src][dst] = 1;
        //meta->edges[dst][src] = 1;
        if (meta->states[dst] == VertexState::Open && meta->parent[src] != dst) {
            //we met this vertex before on the path
            meta->hasCycle = true;
            return true;
        }
    } else {
        if (meta->edges[src][dst] != color) {
            // we have already visited this vertex through parallel edge - also consider as a loop
            meta->hasCycle = true;
            return true;
        }
    }

    return false;
}

bool isCyclic(vector<int> adj[], int V) {
    // idea is to DFS and if we located already opened verticies - it means we have cycle;
    DFSMeta meta(V);
    meta.onEdge = OnEdgeHandler;

    for (int i = 0; i < V; i++) {
        if (meta.states[i] == VertexState::None)
            dfs(i, adj, meta, 1);
    }

    return meta.hasCycle;
}
