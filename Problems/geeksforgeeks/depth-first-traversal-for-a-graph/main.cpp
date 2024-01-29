#include <utils.h>
#include <array>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/* Function to do DFS of graph
 *  g[]: array of vectors to represent graph
 *  vis[]: array to keep track of visited vertex
 */
void dfs(int s, vector<int> g[], bool vis[]) {
    cout << s << " ";
    vis[s] = true;
    for (int i = 0; i < g[s].size(); i++) {
        if (vis[g[s][i]] == false)
            dfs(g[s][i], g, vis);
    }
}

// Position this line where user code will be pasted.
int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<int>* g = new vector<int>[N];
        bool* vis = new bool[N];

        memset(vis, false, sizeof(bool) * N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, g, vis);

        delete[] g;
        delete[] vis;

        cout << endl;
    }
}
