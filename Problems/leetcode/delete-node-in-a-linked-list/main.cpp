#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;
        while (node->next != nullptr) {
            node->val = node->next->val;
            if (node->next->next == nullptr) {
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
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

        int n, v;
        cin >> n >> v;

        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        ListNode *nodeToDel = nullptr;
        for (int j = 0; j < n; j++) {
            ListNode* node = new ListNode(0);

            cin >> node->val;
            node->next = nullptr;

            if (head == 0) {
                head = node;
                prev = node;
            } else {
                prev->next = node;
                prev = node;
            }

            if (node->val == v)
                nodeToDel = node;
        }

        Solution s;
        s.deleteNode(nodeToDel);
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
}