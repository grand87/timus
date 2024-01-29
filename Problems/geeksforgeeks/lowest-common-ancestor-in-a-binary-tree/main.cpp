#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;
/* A binary tree node has data, pointer to left child
    and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
Node * LCA(Node*, int, int);
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
                Node * k = LCA(root, a, b);
                cout << k->data << endl;
            }
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
int data;
Node* left, * right;
}; */
/*you are required to
complete this function */

typedef map<int, Node*> NodePath;

bool locate(Node* root, int n1, NodePath& path) {
    if (root == NULL)
        return false;
    if (root->data == n1) {
        path[root->data] = root;
        return true;
    }
    if (locate(root->left, n1, path)) {
        path[root->data] = root;
        return true;
    }
    else if (locate(root->right, n1, path)) {
        path[root->data] = root;
        return true;
    }
    return false;
}

Node * LCA(Node* root, int n1, int n2)
{
    NodePath pathToN1;

    //build path as set of nodes to n1
    locate(root, n1, pathToN1);

    //build path as set of nodes to n2 & search where intersects with n1's path
    NodePath pathToN2;
    locate(root, n2, pathToN2);

    for (NodePath::reverse_iterator it = pathToN2.rbegin(); it != pathToN2.rend(); it++) {
        //check is there such node in the path to n1
        NodePath::iterator nodeInN1Path = pathToN1.find(it->first);
        if (nodeInN1Path != pathToN1.end())
            return nodeInN1Path->second;
    }

    return nullptr;
}