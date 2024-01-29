#include <iostream>
#include <map>
#include <assert.h>

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
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
/* Function to get diameter of a binary tree */
long long treePathsSum(Node *root);
/* Driver program to test size function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int t;
    scanf("%d", &t);
        while (t--)
        {
            map<int, Node*> m;
            int n;
            scanf("%d", &n);
            struct Node *root = NULL;
            struct Node *child;
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
            cout << treePathsSum(root) << endl;
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
struct Node
{
int data;
Node* left, *right;
}; */
/*You are required to complete below method */

long long treePathsSum(Node *root, long long value) {
    long long sum = 0;
    if (root) {
        if (root->left) {
            sum += treePathsSum(root->left, value * 10 + root->data * 10);
        }
        if (root->right) {
            sum += treePathsSum(root->right, value * 10 + root->data * 10);
        }
        if (!root->left && !root->right) {
            sum = value + root->data;
        }
    }
    return sum;
}

long long treePathsSum(Node *root)
{
    long long sum = 0;
    if (root) {
        if (root->left)
            sum += treePathsSum(root->left, root->data * 10);
        if (root->right)
            sum += treePathsSum(root->right, root->data * 10);
        if (!root->left && !root->right)
            sum = root->data;
    }

    return sum;
}
