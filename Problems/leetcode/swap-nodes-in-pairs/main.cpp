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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = head->next;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr && current->next != nullptr) {
            ListNode* nextHead = current->next->next;
                
            //swap nodes
            ListNode* tmp2 = current->next;
            current->next = nextHead;
            tmp2->next = current;

            if (prev) {
                prev->next = tmp2;
            }

            prev = current;
            current = nextHead;
        }

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
        int n;
        cin >> n;
        ListNode* node = readList<int>(cin, n);
        Solution s;
        node = s.swapPairs(node);
        printList(cout, node);
        cout << endl;
    }
    return 0;
}