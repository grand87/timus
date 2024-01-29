#include <iostream>
#include <map>
#include <vector>

using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
    malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int findDist(Node*, int, int);

/* Driver program to test size function*/
int main() {
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
        if (n == 1)
        {
            int a;
            cin >> a;
            cout << a << endl;
        }
        else {
            while (n--)
            {
                Node *parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
            int a, b;
            cin >> a >> b;
            cout << findDist(root, a, b) << endl;
        }
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b
   in a tree with given root*/
bool search(Node* root, int a, int* path) {
    if (root->data == a) {
        path[root->data] = 1;
        return true;
    }
    else {
        if (root->left && search(root->left, a, path)) {
            path[root->data] = 1;
            return true;
        }
        if (root->right && search(root->right, a, path)) {
            path[root->data] = 1;
            return true;
        }
    }
    return false;
}

int findDist(Node* root, int a, int b)
{
    int paths[2][100];
    for (int i = 0; i < 100; i++) {
        paths[0][i] = 0;
        paths[1][i] = 0;
    }
    search(root, a, paths[0]);
    search(root, b, paths[1]);

    //search intersect between two nodes
    int commonParent = -1;
    for (int i = 99; i >= 0; i--) {
        if (paths[0][i] == 1 && paths[0][i] == paths[1][i]) {
            commonParent = i;
            break;
        }
    }

    // count jumps from each node to intersect node
    int jumps[2] = { 0 , 0 };
    for (int i = a - 1; i >= commonParent; i--) {
        if (paths[0][i] == 1) {
            jumps[0]++;
        }
    }

    for (int i = b - 1; i >= commonParent; i--) {
        if (paths[1][i] == 1) {
            jumps[1]++;
        }
    }

    return jumps[0] + jumps[1];
}