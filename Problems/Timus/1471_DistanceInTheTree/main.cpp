#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef pair<int, int> Edge;
typedef vector<Edge> EdgeList;
typedef vector<EdgeList> Tree;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif

    int vertices;
    cin >> vertices;

    Tree tree;
    tree.reserve(vertices);
    tree.resize(vertices);

    int u, v, w;
    int maxEdges = 0;
    int rootId = 0;

    for (int i = 0; i < vertices - 1; ++i)
    {
        cin >> u >> v >> w;

        tree[u].push_back(Edge(v, w));
        tree[v].push_back(Edge(u, w));

        int localMaxID = u;
        if (tree[v].size() > tree[u].size())
            localMaxID = v;

        if (tree[localMaxID].size() > maxEdges)
        {
            maxEdges = tree[localMaxID].size();
            rootId = localMaxID;
        }
    }

    //based on adjacency list need to generate tree with information where is root\parrent for this node
    // need to select root - let's root will be vertex with max amount of edges
    //based on depth first search - we will build array dist[i] - distance from root to the ith vertex

    vector<int> dist(vertices);
    dist.resize(vertices);
    dist[0] = 0;

    vector<int> visited(vertices);
    visited.resize(vertices);
    memset(&visited[0], 0, (sizeof visited[0]) * vertices);

    vector<pair<int, int> > parent(vertices);
    parent.resize(vertices);
    parent[0] = pair<int, int>(0,0);

    list<int> q;
    q.push_back(rootId);

    while (q.size())
    {
        int vID = q.back();
        q.pop_back();
        
        visited[vID] = 1;

        const int edges = tree[vID].size();

        for (int i = 0; i < edges; ++i)
        {
            int nID = tree[vID][i].first;
            if (!visited[nID])
            {
                dist[nID] = dist[vID] + tree[vID][i].second;
                q.push_back(nID);
                parent[nID] = pair<int,int>(vID, parent[vID].second + 1);
            }
        }
    }

    //need to generate paths from root to all vertices
    // then query will be solved based on LCA(u,v)
    // l = LCA(u,v)
    // ld = distance from root to ld
    // answer = ld - lu + ld - lv, where lu & lv - distances from root to the u & v verticies

    int queries;
    cin >> queries;

    for (int i = 0; i < queries; ++i)
    {
        cin >> u >> v;

        if (u == rootId)
        {
            cout << dist[v] << endl;
        }
        else if (v == rootId)
        {
            cout << dist[u] << endl;
        }
        else
        {
            if (parent[u].first == v)
            {
                cout << abs(dist[u] - dist[v]) << endl;
            }
            else if (parent[v].first == u)
            {
                cout << abs(dist[v] - dist[u]) << endl;
            }
            else
            {
                // need to locate the minimal common parent (LCA)
                int uP = parent[u].first;
                int vP = parent[v].first;

                while(uP != vP)
                {
                    if (parent[uP].second > parent[vP].second)
                    {
                        uP = parent[uP].first;
                    }
                    else if (parent[vP].second > parent[uP].second)
                    {
                        vP = parent[vP].first;
                    }
                    else
                    {
                        uP = parent[uP].first;
                        vP = parent[vP].first;
                    }
                }
                
                //uP is LCA
                cout << dist[u] - dist[uP] + dist[v] - dist[uP] << endl;
            }
        }
    }
}