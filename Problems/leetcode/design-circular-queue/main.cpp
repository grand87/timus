#include <assert.h>
#include <utils.h>

class MyCircularQueue {
    int* buffer;
    int size;
    int back;
    int front;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        buffer = new int[k];
        size = k;
        back = 0;
        front = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (front + 1 <= size || (front + 1) % size <= back) {
            buffer[front % size] = value;
            front++;
            if (front > size)
                front %= size;
            return true;
        }
        return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (front != back) {
            // int tmp = buffer[back];
            back = (back + 1) % size;
            return true;
        }
        return false;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (front != back) {
            return buffer[back];
        }
        return -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (front <= back) {
            return buffer[(front + size - 1) % size];
        }
        return -1;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == back;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front % size == back;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue* circularQueue = new MyCircularQueue(3);  // set the size to be 3
    assert(circularQueue->enQueue(1));                        // return true
    assert(circularQueue->enQueue(2));                        // return true
    assert(circularQueue->enQueue(3));                        // return true
    assert(circularQueue->enQueue(4) == false);               // return false, the queue is full
    assert(circularQueue->Rear() == 3);                       // return 3
    assert(circularQueue->isFull());                          // return true
    assert(circularQueue->deQueue());                         // return true
    assert(circularQueue->enQueue(4));                        // return true
    assert(circularQueue->Rear() == 4);                       // return 4
    return 0;
}