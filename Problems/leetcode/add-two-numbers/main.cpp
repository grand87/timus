#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    int reverse(ListNode* &l) const {
        if (l->next == nullptr)
            return 1;

        int count = 0;
        ListNode *tmp = nullptr;
        ListNode *prev = nullptr;
        while (l != nullptr) {
            ListNode *tmp = l->next;
            l->next = prev;
            prev = l;
            l = tmp;
            count++;
        }
        l = prev;
        return count;
    }

    int count(ListNode* l) const {
        if (l->next == nullptr)
            return 1;

        int count = 0;
        while (l != nullptr) {
            l = l->next;
            count++;
        }
        return count;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        const int s1 = count(l1);
        const int s2 = count(l2);

        if (s1 < s2) {
            swap(l1, l2);
        }

        ListNode* result = nullptr;
        int carry = 0;
        while (l1 || carry > 0) {
            const int v1 = l1 != nullptr ? l1->val : 0;
            const int v2 = l2 != nullptr ? l2->val : 0;

            int newVal = v1 + v2 + carry;
            if (newVal >= 10) {
                carry = 1;
                newVal -= 10;
            }
            else
                carry = 0;
           
            ListNode* tmp = new ListNode(newVal);
            tmp->next = result;
            result = tmp;
            
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        reverse(result);

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

       int n1 = 0, n2 = 0;
       cin >> n1 >> n2;

       ListNode* l1 = nullptr;
       for (int i = 0; i < n1; i++) {
           int tmp = 0;
           cin >> tmp;
           ListNode* newNode = new ListNode(tmp);
           if (l1 != nullptr) {
               newNode->next = l1;
           }
           l1 = newNode;
       }

       ListNode* l2 = nullptr;
       for (int i = 0; i < n2; i++) {
           int tmp = 0;
           cin >> tmp;
           ListNode* newNode = new ListNode(tmp);
           if (l2 != nullptr) {
               newNode->next = l2;
           }
           l2 = newNode;
       }

       Solution s;
       ListNode* a = s.addTwoNumbers(l1, l2);
       while (a != nullptr) {
           cout << a->val << " ";
           a = a->next;
       }

       cout << endl;
   }
}