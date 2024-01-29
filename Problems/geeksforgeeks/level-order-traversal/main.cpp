#include <iostream>
#include <map>
#include <queue>

using namespace std;
void levelOrder(struct Node* node);
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void levelOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
search tree, print out its data elements in
increasing sorted order.*/
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}
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
            scanf("%d", &n);
            struct Node *node = NULL;
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
                    if (node == NULL)
                        node = parent;
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
            levelOrder(node);
            cout << endl;
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
int data;
Node* left, * right;
}; */
//You are required to complete this method
void levelOrder(Node* node)
{
    queue<Node*> level;

    level.push(node);
    while (level.size()) {
        Node* current = level.front();
        cout << current->data << " ";

        if(current->left)
            level.push(current->left);
        if (current->right)
            level.push(current->right);
        level.pop();
    }
}
