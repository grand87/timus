#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

using namespace std;

class MyLinkedList {
    struct Node {
        int value;
        Node* next;
    };

    class NodePool {
        Node pool[1000];
        Node* freePool[1000];
        int size;
        int poolPos;
        int freePoolPos;
    public:

        NodePool() {
            size = 1000;
            poolPos = 0;
            freePoolPos = 0;
        }

        Node* alloc() {
            if (poolPos < size)
                return &pool[poolPos++];
            else
                return nullptr;
        }

        void free(Node* node) {
            if(node != nullptr)
                freePool[freePoolPos++] = node;
        }
    };

    NodePool pool;
    int size;
    Node* head;
    Node* tail;
public:
    
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >=0 && index < size) {
            int pos = 0;
            Node* current = head;
            while (pos < index) {
                current = current->next;
                pos++;
            }
            return current->value;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newNode = pool.alloc();
        newNode->next = head;
        newNode->value = val;
        head = newNode;

        if (newNode->next == nullptr) //if previously list was empty - tail now should link to head
            tail = newNode;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (tail != nullptr) {
            Node* newNode = pool.alloc();
            newNode->next = nullptr;
            newNode->value = val;
            tail->next = newNode;
            tail = newNode;
            size++;
        }
        else
            addAtHead(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        index = max(index, 0);
        if (index > size)
            return;

        if (index == size) {
            addAtTail(val);
        }
        else if (index == 0) {
            addAtHead(val);
        }
        else if (index < size) {
            int pos = 0;
            Node *current = head;
            while (pos < index - 1) {
                current = current->next;
                pos++;
            }
            Node* newNode = pool.alloc();
            newNode->next = current->next;
            newNode->value = val;
            current->next = newNode;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            Node* toDelete = nullptr;
            if (index == 0) {
                //delete head
                toDelete = head;
                head = head->next;
                if (tail == toDelete) //size == 1
                    tail = head;
            }
            else {
                int pos = 0;
                Node *current = head;
                while (pos < index - 1) {
                    current = current->next;
                    pos++;
                }
                toDelete = current->next;
                if (toDelete == tail) //need to update tail
                    tail = current;
                else
                    current->next = toDelete->next;
            }
            pool.free(toDelete);
            size--;
        }
    }
};

int main()
{
    MyLinkedList* linkedList = new MyLinkedList();

    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
    assert(linkedList->get(0) == 1);
    assert(linkedList->get(1) == 2);
    assert(linkedList->get(2) == 3);
    assert(linkedList->get(-1) == -1);
    linkedList->deleteAtIndex(1);
    assert(linkedList->get(-3) == -1);
    linkedList->deleteAtIndex(1);
    linkedList->deleteAtIndex(0);
    assert(linkedList->get(0) == -1);


    //empty list
    linkedList->addAtIndex(-1, 0);
    assert(linkedList->get(0) == -1);
    linkedList->deleteAtIndex(-1);
    assert(linkedList->get(0) == -1);
    //empty list
    
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
    assert(linkedList->get(0) == 1);
    assert(linkedList->get(1) == 2);
    assert(linkedList->get(2) == 3);

    linkedList->deleteAtIndex(1);  // now the linked list is 1->3
    assert(linkedList->get(1) == 3);

    linkedList->deleteAtIndex(0);
    assert(linkedList->get(0) == 3);
    linkedList->deleteAtIndex(0);
    assert(linkedList->get(0) == -1);

    //empty list
    linkedList->addAtHead(3);
    linkedList->addAtHead(2);
    linkedList->addAtHead(1);
    linkedList->deleteAtIndex(3);
    assert(linkedList->get(0) == 1);
    assert(linkedList->get(1) == 2);
    assert(linkedList->get(2) == 3);
    linkedList->deleteAtIndex(2);
    assert(linkedList->get(0) == 1);
    assert(linkedList->get(1) == 2);
    linkedList->deleteAtIndex(1);
    assert(linkedList->get(0) == 1);
    linkedList->deleteAtIndex(0);
    assert(linkedList->get(0) == -1);

    delete linkedList;
}