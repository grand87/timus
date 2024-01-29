#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef Node<int> ListNode;

class Solution {
public:
    ListNode* reverse(ListNode* head, int count, ListNode** newHead) {
        ListNode* prev = nullptr;

        ListNode* current = head;
        ListNode* next = current->next;

        for (int i = 0; i < count; i++) {
            ListNode* tmp = next != nullptr ? next->next : nullptr;
            current->next = prev;
            prev = current;
            current = next;
            next = tmp;
        }

        if (newHead != nullptr)
            *newHead = prev;

        return current;
    }

    int getListSize(ListNode* head) const {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // tmp = current // tmp will become tail of updated part of linked list
        ListNode* nextChain = head;
        ListNode* newHead = nullptr;
        ListNode* oldChankEnd = nullptr;

        int remaining = getListSize(head);
        if (k > remaining)
            return head;

        while (remaining >= k) {
            ListNode* chankStart = nullptr;
            nextChain = reverse(head, k, &chankStart);
            if (oldChankEnd != nullptr) {
                oldChankEnd->next = chankStart;
            }
            oldChankEnd = head;

            if (newHead == nullptr) {
                newHead = chankStart;
            }

            head = nextChain;
            remaining -= k;
        }

        if (remaining != 0)
            oldChankEnd->next = nextChain;

        return newHead;
    }
};

int main() {
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        ListNode* node = readList<int>(cin, n);

        Solution s;

        // ListNode* tmp = nullptr;
        // ListNode* tmp2 = nullptr;
        // ListNode* oldChankEnd = nullptr;

        // ListNode* nextChankStart = s.reverse(node, 3, &tmp);
        // oldChankEnd = node;
        // node = nextChankStart;
        // nextChankStart = s.reverse(node, 2, &tmp2);
        // oldChankEnd->next = tmp2;
        // oldChankEnd = node;
        // node->next = nextChankStart;

        node = s.reverseKGroup(node, k);
        printList(cout, node);
        cout << endl;
    }
    return 0;
}