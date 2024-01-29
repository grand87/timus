#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void printPaths(struct Node *root);
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void inorder(struct Node* root)
{
    if (root == NULL)return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    struct Node *child;
    cin >> t;
    while (t--)
    {
        map<int, Node*> m;
        int n;
        cin >> n;
        struct Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            cin >> n1 >> n2 >> lr;
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
        printPaths(root);
        cout << endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of Node
struct Node
{
int data;
Node* left;
Node* right;
};*/
/* The function should print all the paths from root
to leaf nodes of the binary tree */

void dumpPath(const vector<int>& path, int level) {
    for (int i = 0; i < level; i++)
        cout << path[i] << " ";
    cout << "#";
}

void preorder(Node* root, vector<int>& path, int level) {
    path.push_back(root->data);
    if (root->left == nullptr && root->right == nullptr) {
        //we are in leaf
        dumpPath(path, level);
    } else {
        if (root->left) {
            preorder(root->left, path, level + 1);
            path.pop_back();
        }
        if (root->right) {
            preorder(root->right, path, level + 1);
            path.pop_back();
        }
    }
}

void printPaths(Node* root)
{
    vector<int> currentPath;

    //using preorder non recursive approach
    preorder(root, currentPath, 1);
}
