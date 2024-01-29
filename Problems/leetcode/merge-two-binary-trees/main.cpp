#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;

typedef BinaryTreeNode<int> TreeNode;

class Solution {

    TreeNode* mergeTreesImpl(TreeNode* &root, TreeNode* t1, TreeNode* t2) {
        if (t1 != nullptr && t2 != nullptr) {
            t1->val += t2->val;
            mergeTreesImpl(t1->left, t1->left, t2->left);
            mergeTreesImpl(t1->right, t1->right, t2->right);
        }
        else {
            if (t1 != nullptr)
                root = t1;
            if (t2 != nullptr)
                root = t2;
        }
        return t1;
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)
            swap(t1, t2);
        return mergeTreesImpl(t1, t1, t2);
    }
};

TreeNode* readTree(int count, int root) {
    unordered_map<int, TreeNode*> tree;

    //create root
    tree[root] = new TreeNode(root);

    for (int i = 0; i < count - 1; i++) {
        int parent;
        char pos;
        int val;

        cin >> parent >> pos >> val;
        tree[val] = new TreeNode(val);

        if (pos == 'L')
            tree[parent]->left = tree[val];
        else
            tree[parent]->right = tree[val];
    }

    return tree[root];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int t1Nodes = 0, t1Root = 0;
        cin >> t1Nodes >> t1Root;

        int t2Nodes = 0, t2Root = 0;
        cin >> t2Nodes >> t2Root;

        TreeNode* t1 = readTree(t1Nodes, t1Root);
        TreeNode* t2 = readTree(t2Nodes, t2Root);
        
        Solution s;
        t1 = s.mergeTrees(t1, t2);
    }
}