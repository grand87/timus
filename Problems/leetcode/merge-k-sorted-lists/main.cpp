#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>
#include <utils.h>

using namespace std;


typedef Node<int> ListNode;

class Solution {
    int getMinNode(const vector<ListNode*>& lists, int &countNodes) const {
        int minIndex = -1;
        const ListNode* minNode = nullptr;
        countNodes = 0;
        for (int i = 0; i < lists.size(); i++) {
            const ListNode* node = lists[i];
            if (node != nullptr) {
                countNodes++;
                if (minNode == nullptr) {
                    minNode = node;
                    minIndex = i;
                }  else {
                    if (node->val < minNode->val) {
                        minNode = node;
                        minIndex = i;
                    }
                }
            }
        }
        return minIndex;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = nullptr;
        ListNode* current = nullptr;
        
        int validNodesCount = 0;
        int minNodeIndex = getMinNode(lists, validNodesCount);
        
        while (minNodeIndex != -1 && validNodesCount > 1) {
            ListNode* node = lists[minNodeIndex];

            if (result == nullptr) {
                result = node;
            } else {
                current->next = node;
            }
            current = node;

            lists[minNodeIndex] = lists[minNodeIndex]->next;
            //potential optimiszation is to remove nullptr nodes from the lists to speed-up getMinNode API

            current->next = nullptr;

            minNodeIndex = getMinNode(lists, validNodesCount);
        }

        if (validNodesCount == 1) {
            if (current == nullptr) {
                result = lists[minNodeIndex];
            } else {
                current->next = lists[minNodeIndex];
            }
        }
        
        return result;
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

        int n = 0;
        cin >> n;

        vector<ListNode*> lists(n);
        {
            vector<int> size(n);
            readVector(cin, size, n);
            for (int l = 0; l < n; l++) {
                lists[l] = readList<int>(cin, size[l]);
            }
        }
        
        Solution s;
        ListNode* res = s.mergeKLists(lists);

        printList<int>(cout, res);

        cout << endl;
    }

}