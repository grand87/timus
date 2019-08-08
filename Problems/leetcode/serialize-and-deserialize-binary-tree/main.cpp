#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Codec {
    struct NodeParent {
        int parent;
        bool isLeft;

        NodeParent(int p = -1, bool left = false) : parent(p), isLeft(left) {
        }
    };

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<pair<int, NodeParent>> tree;

        if (root != nullptr) {
            stack<pair<TreeNode*, NodeParent>> nodes;

            // root will have associated value as -1
            nodes.push(make_pair(root, NodeParent(-1, false)));
            while (!nodes.empty()) {
                pair<TreeNode*, NodeParent> current = nodes.top();
                nodes.pop();

                tree.push_back(make_pair(current.first->val, current.second));
                const int parentId = tree.size() - 1; 
                if (current.first->left != nullptr)
                    nodes.push(make_pair(current.first->left, NodeParent(parentId, true)));
                if (current.first->right != nullptr)
                    nodes.push(make_pair(current.first->right, NodeParent(parentId, false)));
            }
        }

        stringstream str;
        str << tree.size();
        for (auto rec : tree) {
            str << " " << rec.first << " " << rec.second.parent << " " << rec.second.isLeft;
        }

        return str.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str(data);

        int nodesCount;
        str >> nodesCount;

        if (nodesCount) {
            vector<TreeNode*> nodes;
            int rootId, nodeId, parentId, isLeft;

            // read root
            str >> rootId >> parentId >> isLeft;
            TreeNode* node = new TreeNode(rootId);
            node->left = nullptr;
            node->right = nullptr;
            nodes.push_back(node);

            for (int i = 1; i < nodesCount; i++) {
                str >> nodeId >> parentId >> isLeft;
                TreeNode* node = new TreeNode(nodeId);
                node->left = nullptr;
                node->right = nullptr;
                nodes.push_back(node);

                if (isLeft)
                    nodes[parentId]->left = node;
                else
                    nodes[parentId]->right = node;
            }

            return nodes[0];
        }

        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    //string str = "5 1 -1 0 2 1 1 3 1 0 4 3 1 5 3 0 ";
    //string str = "3 2 -1 0 1 2 1 3 2 0";
    string str = "4 3 -1 0 4 3 0 2 3 1 3 2 1";

    Codec c;
    TreeNode* n = c.deserialize(str);
    string str2 = c.serialize(n);

    return 0;
}
