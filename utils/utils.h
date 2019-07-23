#ifndef __PROBLEMS_UTILS_H__
#define __PROBLEMS_UTILS_H__

#include <vector>
#include <iostream>

template<typename T>
void readVector(std::istream& is, std::vector<T>& vec, int count) {
    for (int i = 0; i < count; i++) {
        is >> vec[i];
    }
};

template<typename T>
void printVector(std::ostream& is, const std::vector<T>& vec, char seperator = ' ') {
    for (std::vector<T>::size_type i = 0; i < vec.size(); i++) {
        cout <<vec [i] << seperator;
    }
};

template<typename T>
struct Node {
    T val;
    Node *next;
    Node(T x) : val(x), next(NULL) {}
};

template<typename T>
Node<T>* readList(std::istream& is, int count) {
    Node<T>* head = nullptr;
    Node<T>* current = nullptr;
    for (int i = 0; i < count; i++) {
        T val;
        cin >> val;
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
};

template<typename T>
void printList(std::ostream& is, const Node<T>* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

#endif /*__PROBLEMS_UTILS_H__*/