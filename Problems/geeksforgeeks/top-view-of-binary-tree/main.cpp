#include<iostream>
#include<map>
#include<vector>
#include<vector>
#include<queue>
#include<utility>
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
void topView(struct Node *root);
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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
            topView(root);
            cout << endl;
        }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//Structure of binary tree
/*struct Node
{
int data;
struct Node* left;
struct Node* right;
};*/
// function should print the topView of the binary tree

typedef pair<int, Node*> LevelNode;

void topView(struct Node *root)
{
    //need to make in order level traversal and print the first + last node for every level starting from root

    vector<vector<LevelNode>> levels;


    queue<LevelNode> currentLevel;
    queue<LevelNode> nextLevel;

    currentLevel.push(LevelNode(0,root));
    levels.push_back(vector<LevelNode>());

    while (currentLevel.size()) {
        LevelNode& currentNode = currentLevel.front();

        const int levelIndex = levels.size() - 1;
        levels[levelIndex].push_back(currentNode);

        if (currentNode.second->left)
            nextLevel.push(LevelNode(currentNode.first - 1, currentNode.second->left));
        if (currentNode.second->right)
            nextLevel.push(LevelNode(currentNode.first + 1, currentNode.second->right));

        currentLevel.pop();
        if (currentLevel.empty()) {
            //start to proceed next level
            if (nextLevel.size())
                levels.push_back(vector<LevelNode>());
            swap(currentLevel, nextLevel);
        }
    }

    int leftDistance = 0;
    int rightDistance = 0;

    if (root) {
        cout << levels[0][0].second->data << " ";

        for (int i = 1; i < levels.size(); i++) {
            vector<LevelNode>& prevLevel = levels[i - 1];
            vector<LevelNode>& currentLevel = levels[i];
            sort(currentLevel.begin(), currentLevel.end());

            if (currentLevel[0].first < leftDistance) {
                cout << currentLevel[0].second->data << " ";
                leftDistance = currentLevel[0].first;
            }
            if (currentLevel[currentLevel.size() - 1].first > rightDistance) {
                cout << currentLevel[currentLevel.size() - 1].second->data << " ";
                rightDistance = currentLevel[currentLevel.size() - 1].first;
            }
        }
    }
}