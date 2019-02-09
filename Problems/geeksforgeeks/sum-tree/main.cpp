#include<iostream>
#include<map>
#include<algorithm>

using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
bool isSumTree(struct Node* node);
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
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
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
            cout << isSumTree(root) << endl;
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Tree node
struct Node
{
int data;
Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

int sum(Node* root) {
    int res = 0;
    if (root) {
        res += root->data;
        if (root->left)
            res += sum(root->left);
        if (root->right)
            res += sum(root->right);
    }
    return res;
}

bool isSumTree(Node* root)
{
    bool result = false;
    if (root) {
        if (root->left || root->right) {
            int total = sum(root->left) + sum(root->right);
            result = (total == root->data);
        }
        else
            result = true;

        if (!result)
            return false;
        if (root->left) {
            result = isSumTree(root->left);
            if (!result)
                return false;
        }
        if (root->right)
            result = isSumTree(root->right);
        return result;
    }
    else
        return true;
}