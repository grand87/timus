#include<iostream>
#include<algorithm>

using namespace std;

int net[1000][1000];
bool visited[1000] = {false};

int getFirstUnvistedNode(bool* nodes, int size) {
    for (int i = 0; i < size; i++)
        if (!nodes[i])
            return i;
    return size;
}

int dfs(int nodeIndex, int net[1000][1000], bool* visited, int nodesCount) {
    int vistis = 0;
    if (!visited[nodeIndex]) {
        vistis++;
        visited[nodeIndex] = true;
        for (int i = 0; i < nodesCount; i++) {
            if (net[nodeIndex][i]) {
                vistis += dfs(i, net, visited, nodesCount);
            }
        }
    }
    return vistis;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//#endif
    int friends;
    cin >> friends;

    for (int i = 0; i < friends; i++)
        for (int j = 0; j < friends; j++)
            cin >> net[i][j];

    int nodesVisited = 0;
    int nodeIndex = getFirstUnvistedNode(visited, friends);
    int paths = 1;

    while (nodesVisited < friends && nodeIndex < friends) {
        nodesVisited += dfs(nodeIndex, net, visited, friends);
        if (nodesVisited < friends) {
            paths++;
            nodeIndex = getFirstUnvistedNode(visited, friends);
        }
    }
    cout << paths;

    return 0;
}