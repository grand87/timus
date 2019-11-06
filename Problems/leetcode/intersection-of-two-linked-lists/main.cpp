#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> cacheNodes;
        while (headA != nullptr) {
            cacheNodes.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (cacheNodes.find(headB) != cacheNodes.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

ListNode* reverseList(ListNode* list) {
    ListNode* prev = nullptr;
    while (list != nullptr) {
        ListNode* tmp = list->next;
        list->next = prev;
        prev = list;
        list = tmp;
    }
    return prev;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {

        int n = 0, k = 0;
        cin >> n >> k;

        ListNode* l1 = nullptr;
        for (int j = 0; j < n; j++) {
            int data;
            cin >> data;
            ListNode* tmp = new ListNode(data);
            tmp->next = l1;
            l1 = tmp;
        }
        l1 = reverseList(l1);

        ListNode* l2 = nullptr;
        for (int j = 0; j < k; j++) {
            int data;
            cin >> data;
            ListNode* tmp = new ListNode(data);
            tmp->next = l2;
            l2 = tmp;
        }
        l2 = reverseList(l2);

        Solution s;

        ListNode *res = s.getIntersectionNode(l1, l2);
        if (res == nullptr)
            cout << "null";
        else
            cout << res->val;
        cout << endl;
    }
}