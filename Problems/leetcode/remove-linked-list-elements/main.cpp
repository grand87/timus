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
    ListNode* removeElements(ListNode* head, int val) {
        //search for a proper head
        while (head != nullptr && head->val == val)
            head = head->next;

        if (head == nullptr)
            return nullptr;
        ListNode* prev = head;
        ListNode* current = head->next;
        
        while (current != nullptr) {
            if (current->val == val) {
                prev->next = current->next;
            } else
                prev = prev->next;
            current = current->next;
        }
        return head;
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
        }

        Solution s;
        cout << s.removeElements(head, v) << endl;
    }
}