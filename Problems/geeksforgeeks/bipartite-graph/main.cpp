#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAX = 100;

bool isBipartite(int G[][MAX], int V);

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t;
    cin >> t;
    int g[MAX][MAX];
    while (t--) {
        memset(g, 0, sizeof(g));
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }

        cout << isBipartite(g, n) << endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
 *   V: number of vertices
 *   adj[]: representation of graph
 */

enum class VertexState : char { None = 0, Open, Done };

struct GraphMeta {
    typedef bool (*OnVertexEnter)(int v, vector<int> adj[], GraphMeta* meta);
    typedef bool (*OnVertexExit)(int v, vector<int> adj[], GraphMeta* meta);
    typedef bool (*OnEdge)(int src, int dst, vector<int> adj[], GraphMeta* meta, int color);

    OnVertexEnter onVertexEnter;
    OnVertexExit onVertexExit;
    OnEdge onEdge;

    vector<vector<int>> edges;
    vector<VertexState> states;

    bool hasCycle;

    vector<int> parent;

    GraphMeta(int n) : edges(n), states(n), parent(n) {
        onVertexEnter = nullptr;
        onVertexExit = nullptr;
        onEdge = nullptr;
        hasCycle = false;

        for (int i = 0; i < n; i++)
            edges[i].resize(n);
    };
};

void dfs(int v, vector<int> adj[], GraphMeta& meta, int color) {
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

void bfs(int v, int G[][MAX], int count, GraphMeta& meta) {

    meta.states[v] = VertexState::Open;

    queue<int> verts;
    verts.push(v);

    while (!verts.empty()) {
    
    }

    for (int i = 0; i < count; i++) {
        if ()
    }

    meta.states[v] = VertexState::Done;
}

bool isBipartite(int G[][MAX], int V) {
    for (int i = 0; i < V; i++) {
    
    }
}