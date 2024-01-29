#include<iostream>
#include<map>
#include<vector>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
                        // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    struct Node *child;
    scanf("%d", &t);
        while (t--)
        {
            map<int, Node*> m;
            int n;
            scanf("%d",&n);
                struct Node *root = NULL;
            while (n--)
            {
                Node *parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                if (m.find(n1) == m.end())
                {
                    parent = newNode(n1);
                    m[n1] = parent;
                    if (root == NULL)
                        root = parent;
                }
                else
                    parent = m[n1];
                child = newNode(n2);
                if (lr == 'L')
                    parent->left = child;
                else
                    parent->right = child;
                m[n2] = child;
            }
            bottomView(root);
            cout << endl;
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
struct Node
{
int data;
Node *left, *right;
}; */
// Method that prints the bottom view.

typedef pair<int, Node*> hdLevelElement;
typedef vector<Node*> hdNodes;
typedef map<int, hdNodes> HorizontalDistances;

void bottomView(Node *root)
{
    //in order level traversal

    vector< hdLevelElement > level;
    if (root)
        level.push_back(hdLevelElement(0, root));
    int levelPos = 0;

    HorizontalDistances hds;

    vector<hdLevelElement> nextLevel;
    while (levelPos < level.size()) {
        
        hdLevelElement &current = level[levelPos];

        hds[current.first].push_back(current.second);

        if (current.second->left)
            nextLevel.push_back(hdLevelElement(current.first - 1, current.second->left));
        if (current.second->right)
            nextLevel.push_back(hdLevelElement(current.first + 1, current.second->right));
        levelPos++;

        if (levelPos == level.size()) {
            swap(nextLevel, level);
            nextLevel.clear();
            levelPos = 0;
        }
    }

    for (HorizontalDistances::iterator it = hds.begin(); it != hds.end(); it++) {
        //for every horizontal distance locate the bottommost element (pair.a value) and print it, if we do have several bottommost elements - print the latest one
        hdNodes& nodes = it->second;
        cout << (*nodes.rbegin())->data << " ";
    }
}

//void inOrder(Node* tree, HorizontalDistances& hds, int level, int hd) {
//    if (tree) {
//        hds[hd].push_back(pair<int, Node*>(level, tree));
//        inOrder(tree->left, hds, level + 1 ,hd - 1);
//        inOrder(tree->right, hds, level + 1, hd + 1);
//    }
//}

//void bottomView(Node *root)
//{
//    // need to generate map where key is horizontal distance
//    // every the value is list of pairs, where pair - is level of node, and b is Node
//    HorizontalDistances hds;
//    inOrder(root, hds, 0, 0);
//
//    for (HorizontalDistances::iterator it = hds.begin(); it != hds.end(); it++) {
//        //for every horizontal distance locate the bottommost element (pair.a value) and print it, if we do have several bottommost elements - print the latest one
//        hdNodes& nodes = it->second;
//        sort(nodes.begin(), nodes.end());
//        cout << nodes.rbegin()->second->data << " ";
//    }
//}