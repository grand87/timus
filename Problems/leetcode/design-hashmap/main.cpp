#include <assert.h>
#include <utils.h>

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class MyHashMap {
    struct Node {
        int value;
        int key;
        Node* next;
    };

    static const int MAX_NODES = 10000;
    static const int TBL_SIZE = 1000;

    Node pool[MAX_NODES];
    int poolNodes;
    Node* tbl[TBL_SIZE];

    int calculateHash(int value) { return value % TBL_SIZE; }

    Node* allocNode() {
        if (poolNodes < MAX_NODES) {
            Node* res = &pool[poolNodes];
            poolNodes++;
            res->next = nullptr;
            return res;
        }
        return nullptr;
    }

    Node* findNode(int key) {
        const int hash = calculateHash(key);
        Node* current = tbl[hash];
        while (current != nullptr) {
            if (current->key == key) return current;
            current = current->next;
        }
        return nullptr;
    }

   public:
    /** Initialize your data structure here. */
    MyHashMap() : poolNodes(0) {
        for (int i = 0; i < TBL_SIZE; i++) tbl[i] = nullptr;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        Node* current = findNode(key);
        if (current != nullptr)
            current->value = value;
        else {
            const int hash = calculateHash(key);
            Node* node = allocNode();
            node->key = key;
            node->value = value;

            if (tbl[hash] == nullptr) {
                tbl[hash] = node;
            } else {
                node->next = tbl[hash];
                tbl[hash] = node;
            }
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        Node* current = findNode(key);
        if (current != nullptr)
            return current->value;
        else
            return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        const int hash = calculateHash(key);
        Node* current = tbl[hash];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    tbl[hash] = current->next;
                } else {
                    prev->next = current->next;
                }
                break;
            }
            prev = current;
            current = current->next;
        }
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
        MyHashMap hashMap;
        hashMap.put(1, 1);
        hashMap.put(2, 2);
        assert(hashMap.get(1) == -1);  // returns 1
        assert(hashMap.get(3) == -1);  // returns -1 (not found)
        hashMap.put(2, 1);             // update the existing value
        assert(hashMap.get(2) == 1);   // returns 1
        hashMap.remove(2);             // remove the mapping for 2
        assert(hashMap.get(2) == -1);  // returns -1 (not found)
    }
    return 0;
}
