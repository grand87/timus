#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct node {
    node()
    {
        left = nullptr;
        right = nullptr;
    }
    node* left;
    node* right;

    int value;
};

vector<node> nodePool(3000);

struct tree {
    tree()
    {
        root = nullptr;
    }
    node* root;
};

void addToNode(node* p, node* n) {
    if (n->value > p->value) {
        if (p->right == nullptr)
            p->right = n;
        else
            addToNode(p->right, n);
    } else {
        if (p->left == nullptr)
            p->left = n;
        else
            addToNode(p->left, n);
    }
}

void addToTree(tree* t, node* n) {
    if (t->root == nullptr) {
        t->root = n;
    } else {
        addToNode(t->root, n);
    }
}

void dumpNodeRight(node* n) {
    if (n->right)
        dumpNodeRight(n->right);
    if (n->left)
        dumpNodeRight(n->left);
    cout << n->value << endl;
}

void dumpInOrder(tree* t) {
    if (t != nullptr) {
        if (t->root)
            dumpNodeRight(t->root);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif`
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> nodePool[i].value;
    }

    tree t;

    for (int i = n - 1; i >= 0; --i) {
        addToTree(&t, &nodePool[i]);
    }

    dumpInOrder(&t);

    return 0;
}  