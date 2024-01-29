#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

constexpr unsigned int LettersCount = 'z' - 'a' + 1;

class Trie {
    struct TrieNode {
        TrieNode* level[LettersCount];
        bool endWord;

        TrieNode() {
        }

        void reset() {
            memset(this, 0, sizeof(TrieNode));
        }
    };

    class TrieNodePool {
        TrieNode* pool;
        unsigned int pos;

    public:
        TrieNodePool() {
            pos = 0;
            pool = new TrieNode[10000];
        }

        ~TrieNodePool() {
            delete[] pool;
        }

        TrieNode* alloc() {
            TrieNode* node = &pool[pos++];
            node->reset();
            return node;
        }

        void reset() {
            pos = 0;
        }
    };
    TrieNodePool pool;
    TrieNode* root;

public:
    Trie() {
        reset();
    }

    void insert(const char* str) {
        int pos = 0;
        TrieNode *current = root;

        while (str[pos]) {
            const unsigned int charCode = str[pos] - 'a';
            if (current->level[charCode] == nullptr) {
                current->level[charCode] = pool.alloc();
            }
            current = current->level[charCode];
            pos++;
        }
        current->endWord = true;
    }

    bool find(const char* str) {
        int pos = 0;
        TrieNode *current = root;

        while (str[pos]) {
            const unsigned int charCode = str[pos] - 'a';
            if (current->level[charCode] == nullptr) {
                return false;
            }
            current = current->level[charCode];
            pos++;
        }
        return current->endWord;
    }

    void reset() {
        pool.reset();
        root = pool.alloc();
    }
};

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif
    char buffer[100];

    int t;
    cin >> t;

    Trie trie;

    for (int i = 0; i < t; i++) {
        unsigned int n;
        cin >> n;

        trie.reset();

        for (int w = 0; w < n; w++) {
            cin >> buffer;
            trie.insert(buffer);
        }

        cin >> buffer;
        cout << trie.find(buffer) << endl;
    }
    return 0;
}