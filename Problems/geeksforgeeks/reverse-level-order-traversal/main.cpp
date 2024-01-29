#include <iostream>
#include <map>
#include <stack>
#include <list>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void reversePrint(Node *root);
/* Driver program to test above functions*/
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
            scanf("%d",&n);
                Node *root = NULL;
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
                Node *child = newNode(n2);
                if (lr == 'L')
                    parent->left = child;
                else
                    parent->right = child;
                m[n2] = child;
            }
            reversePrint(root);
            cout << endl;
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A tree Node has data, pointer to left child
and a pointer to right child
struct Node
{
int data;
Node* left;
Node* right;
}; */
void reversePrint(Node *root)
{
    stack<list<Node*> > reversedTreeLevels;

    list<Node*> level;
    level.push_back(root);
    reversedTreeLevels.push(level);

    list<Node*> nextLevel;
    //generate stack
    while (!level.empty()) {
        Node* current = level.front();
        if (current->left)
            nextLevel.push_back(current->left);
        if (current->right)
            nextLevel.push_back(current->right);
        level.pop_front();
        if (level.size() == 0) {
            reversedTreeLevels.push(nextLevel);
            swap(level,nextLevel);
        }
    }

    while (!reversedTreeLevels.empty()) {
        const list<Node*>& lastOne = reversedTreeLevels.top();
        for (list<Node*>::const_iterator it = lastOne.begin(); it != lastOne.end(); it++)
            cout << (*it)->data << " ";
        reversedTreeLevels.pop();
    }
}