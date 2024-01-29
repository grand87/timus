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

    void inorderTraversalImpl(TreeNode* root, vector<int>& vec) {
        if (root != nullptr) {
            if (root->left != nullptr)
                inorderTraversalImpl(root->left, vec);
            vec.push_back(root->val);
            if (root->right != nullptr)
                inorderTraversalImpl(root->right, vec);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> s;

        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            res.push_back(current->val);
            current = current->right;
        }

        return res;
    }
};

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

        TreeNode* t1 = readTree<int>(t1Nodes, t1Root);

        Solution s;
        vector<int> res = s.inorderTraversal(t1);
        printVector(cout, res);
        cout << endl;
    }
}