#include <iostream>
#include <vector>

using namespace std;

struct node {

    void addNode(node* n) {
        children.push_back(n);
        n->parent = this;
    }

    node* parent;
    vector<node*> children;
};

node pool[100010];

node* getNode() {
    static int index = 0;
    return &pool[index++];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;

    node *root = getNode();
    root->parent = nullptr;
    node *current = root;

    int rootChildIndex = 0;

    int maxNestingDepth = 0;
    int curNestingDepth = 0;
    int maxNestingDepthPos = 0;

    int maxNestedChildren = 0;
    int curNestedChildren = 0;
    int maxNestedChildrenPos = 0;
    int curNestedChildrenPos = 0;

    int val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (val == 1) {
            if (current == root) {
                curNestedChildrenPos = i;
            }

            node* newNode = getNode();
            current->addNode(newNode);
            current = newNode;
            ++curNestingDepth;
            if (curNestingDepth > maxNestingDepth) {
                maxNestingDepth = curNestingDepth;
                maxNestingDepthPos = i;
            }

            ++curNestedChildren;
            if (curNestedChildren > maxNestedChildren) {
                maxNestedChildren = curNestedChildren;
                maxNestedChildrenPos = curNestedChildrenPos;
            }
            
        } else {
            current = current->parent;
            --curNestingDepth;

            ++curNestedChildren;
            if (curNestedChildren > maxNestedChildren) {
                maxNestedChildren = curNestedChildren;
                maxNestedChildrenPos = curNestedChildrenPos;
            }

            if (current == root) {
                ++rootChildIndex;
                curNestedChildren = 0;
            }
        }
    }

    cout << maxNestingDepth << " " << maxNestingDepthPos + 1 << " " << maxNestedChildren << " " << maxNestedChildrenPos + 1;
}