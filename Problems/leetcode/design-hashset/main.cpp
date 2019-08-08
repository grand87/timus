#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <utils.h>

using namespace std;

class MyHashSet {
    struct Node {
        int key;
        Node* next;
    };

    static const int MAX_NODES = 10000;
    static const int TBL_SIZE = 1000;

    Node pool[MAX_NODES];
    int poolNodes;
    Node* tbl[TBL_SIZE];

    int calculateHash(int value) {
        return value % TBL_SIZE;
    }

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
            if (current->key == key)
                return current;
            current = current->next;
        }
        return nullptr;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() : poolNodes(0){
        for (int i = 0; i < TBL_SIZE; i++)
            tbl[i] = nullptr;
    }

    void add(int key) {
        Node* current = findNode(key);
        if (current == nullptr) {
            const int hash = calculateHash(key);
            Node* node = allocNode();
            node->key = key;

            if (tbl[hash] == nullptr) {
                tbl[hash] = node;
            } else {
                node->next = tbl[hash];
                tbl[hash] = node;
            }
        }
    }

    bool contains(int key) {
        return findNode(key) != nullptr;
    }

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

int main()
{
#ifdef LOCAL_TEST
    std::ifstream in("input.txt");
    cin.set_rdbuf(in.rdbuf());
#endif

    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    assert(hashSet.contains(1));    // returns true
    assert(!hashSet.contains(3));    // returns false (not found)
    hashSet.add(2);
    assert(hashSet.contains(2));    // returns true
    hashSet.remove(2);
    assert(!hashSet.contains(2));    // returns false (already removed)

    return 0;
}
