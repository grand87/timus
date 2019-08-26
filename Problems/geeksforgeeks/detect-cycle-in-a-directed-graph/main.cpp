#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

bool isCyclic(int V, vector<int> adj[]);

// Position this line where user code will be pasted.
int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<int>* adj = new vector<int>[v];

        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(v, adj) << endl;

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
    typedef bool (*OnEdge)(int src, int dst, vector<int> adj[], DFSMeta* meta);

    OnVertexEnter onVertexEnter;
    OnVertexExit onVertexExit;
    OnEdge onEdge;

    vector<VertexState> states;

    bool hasCycle;

    DFSMeta(int n) : states(n) {
        onVertexEnter = nullptr;
        onVertexExit = nullptr;
        onEdge = nullptr;
        hasCycle = false;
    };
};

void dfs(int v, vector<int> adj[], DFSMeta& meta) {
    meta.states[v] = VertexState::Open;

    if (meta.onVertexEnter != nullptr)
        meta.onVertexEnter(v, adj, &meta);

    for (int i = 0; i < adj[v].size(); i++) {
        const int connectedVertex = adj[v][i];
        
        if (meta.onEdge != nullptr)
            meta.onEdge(v, connectedVertex, adj, &meta);
        if (meta.states[connectedVertex] == VertexState::None)
            dfs(connectedVertex, adj, meta);
    }

    meta.states[v] = VertexState::Done;

    if (meta.onVertexExit != nullptr)
        meta.onVertexExit(v, adj, &meta);
}

bool OnEdgeHandler(int src, int dst, vector<int> adj[], DFSMeta* meta) {
    if (meta->states[dst] == VertexState::Open) {
        // dst vertex was met before on the path to the src and means - we have cycle
#ifdef LOCAL_TEST
        cout << "Cycle detected" << endl;
#endif
        meta->hasCycle = true;
        return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    // idea is to DFS and if we located already opened verticies - it means we have cycle;
    DFSMeta meta(V);
    meta.onEdge = OnEdgeHandler;

    for (int i = 0; i < V; i++) {
        if (meta.states[i] == VertexState::None)
            dfs(i, adj, meta);
    }

    return meta.hasCycle;
}
