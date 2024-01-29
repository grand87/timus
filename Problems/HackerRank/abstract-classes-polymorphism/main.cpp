#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
	LRUCache(int capacity) {
		cp = capacity;
		tail = nullptr;
		head = nullptr;
	}

	virtual void set(int key, int value) {
		auto search = mp.find(key);
		Node* node = nullptr;
		if (search == mp.end()) {
			node = new Node(key, value);
			node->key = key;
			mp[key] = node;
		} else {
			node = search->second;
		}
		node->value = value;

		//node should be moved to the head
		if (head) {
			if (node != head) {
				if (node->next && node->prev) {
					//extract from midle and move to head
					node->prev->next = node->next;
					node->next->prev = node->prev;
				}
				else if (node->prev) {
					//extract from end and move to head
					node->prev->next = nullptr;
				}
				node->next = head;
				head->prev = node;
				node->prev = nullptr;
			}
		} else {
			head = node;
			tail = node;
		}

		if (mp.size() > cp) {
			//remove tail
			mp.erase(tail->key);
			tail = tail->prev;
			tail->next = nullptr;
		}
	}

	virtual int get(int key) {
		auto search = mp.find(key);
		if (search == mp.end())
			return -1;
		return search->second->value;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i<n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}