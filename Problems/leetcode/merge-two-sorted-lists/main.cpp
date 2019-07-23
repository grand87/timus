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
    ListNode* mergeTwoListsImpl(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* current = nullptr;

        while (l1 != nullptr && l2 != nullptr) {
            ListNode* newNode = nullptr;
            if (l1->val <= l2->val) {
                newNode = l1;
                l1 = l1->next;
            }
            else {
                newNode = l2;
                l2 = l2->next;
            }

            if (current == nullptr) {
                current = newNode;
                head = current;
            } else {
                current->next = newNode;
                current = newNode;
            }
            current->next = nullptr;
        }

        //some list is become nullptr
        if (l1 != nullptr)
            current->next = l1;
        else
            current->next = l2;


        return head;
    }

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 != nullptr) {
            if (l2 != nullptr) {
                return mergeTwoListsImpl(l1, l2);
            }
            else
                return l1;
        } else {
            if (l2 != nullptr)
                return l2;
            else
                return nullptr;
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

        int n = 0, m = 0;
        cin >> n >> m;
        ListNode* a = readList<int>(cin, n);
        ListNode* b = readList<int>(cin, m);

        Solution s;
        ListNode* res = s.mergeTwoLists(a, b);

        printList<int>(cout, res);

        cout << endl;
    }

}