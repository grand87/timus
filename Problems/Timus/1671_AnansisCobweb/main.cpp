#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int MAX_N = 100001;

struct edge
{
    int first;
    int second;
};

struct DSU
{
    int parent[MAX_N];
    int size;

    DSU()
    {
        memset(parent, 0, MAX_N * sizeof(int));
        size = 0;
    }

    void add(int value)
    {
        parent[value] = value;
        ++size;
    }

    int find_set(int value)
    {
        if (value == parent[value])
            return value;
        return find_set(parent[value]);
    }

    bool union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            parent[b] = a;
            return true;
        }
        return false;
    }
};

edge links[MAX_N];
edge linksSecond[MAX_N];
int toRemove[MAX_N];
DSU dsu;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//   freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    cin >> n >> m;

    //generate disjoint set based on n vertexes
    for (int i = 0; i < n; ++i)
    {
        dsu.add(i + 1);
    }

    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> links[i].first >> links[i].second;
    }

    int r;
    cin >> r;

    for (int i = 0; i < r; ++i)
    {
        int indexToRemove;
        cin >> indexToRemove;

        linksSecond[i] = links[indexToRemove - 1];
        links[indexToRemove - 1].first = -1;
    }

    //insert edges which would not be removed & calculate the amount of sets
    int count = dsu.size;

    for (int i = 0; i < m; ++i)
    {
        if (links[i].first != -1)
            dsu.size -= dsu.union_sets(links[i].first, links[i].second) ? 1 : 0;
    }

    // calculate count of components
    list<int> sizeHistory;
    sizeHistory.push_back(dsu.size);

    //add edges in the reverse of removing order
    for (int e = 0; e < r; ++e)
    {
        edge edgeToAdd = linksSecond[r - e - 1];
        dsu.size -= dsu.union_sets(edgeToAdd.first, edgeToAdd.second) ? 1 : 0;
        sizeHistory.push_back(dsu.size);
    }

    sizeHistory.pop_back();

    for (int i = 0; i < r; ++i)
    {
        cout << sizeHistory.back() << " ";
        sizeHistory.pop_back();
    }
}