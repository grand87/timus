#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[1000] = {0};

class MaxHeap {
    mutable int data[10000];
    int size;
    int capacity;
    mutable bool isUpdated;
    mutable int minValue;

    void heapify_up(int index) {
        // need to confirm that new value does not violite the heap rules it should be less every it's parent
        while (index > 0 && data[index] > data[parent(index)]) {
            swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int index) {
        if (size == 1 || index >= size)
            return;

        int largest = index;
        const int leftChild = left(index);
        const int rightChild = right(index);

        const int valAtleftChild = leftChild < size ? data[leftChild] : 0;
        const int valAtRightChild = rightChild < size ? data[rightChild] : 0;

        if (data[largest] < valAtleftChild) {
            largest = leftChild;
        }

        if (data[largest] < valAtRightChild) {
            largest = rightChild;
        }

        if (index != largest) {
            swap(data[index], data[largest]);
            heapify(largest);
        }
    }

    int parent(int i) const {
        return (i - 1) / 2;
    }

    // to get index of left child of node at index i 
    int left(int i) const {
        return (2 * i + 1);
    }

    // to get index of right child of node at index i 
    int right(int i) const {
        return (2 * i + 2);
    }

public:
    MaxHeap(int aSize) {
        size = 0;
        capacity = aSize;
        isUpdated = false;
    }

    ~MaxHeap() {
    }

    //returns max element at the heap
    int max() const {
        if (size > 0)
            return data[0];
        else
            cout << "error\n";
    }

    //returns max element at the heap
    int min() const {
        if (size > 0) {
            if (isUpdated) {
                int* minElement = min_element(&data[0], &data[0] + size);
                if (minElement != nullptr) {
                    const int indexOfMinElement = minElement - data;
                    if (indexOfMinElement >= 0 && indexOfMinElement < size) {
                        minValue = *minElement;
                        isUpdated = false;
                    }
                }
            }
            return minValue;
        }
        else
            cout << "error\n";
    }

    //removes max element from the heap
    void pop() {
        if (size > 1) {
            swap(data[0], data[size - 1]);
            size--;
            heapify(0);
        }
        else
            size = 0;

#ifdef LOCAL_TEST
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
#endif
        isUpdated = true;
    }

    //add new element to the heap
    void push(int val) {
        if (size < capacity) {
            data[size] = val;
            size++;
            heapify_up(size - 1);
        } else {
            //replace the min element with new value & heapify
            int* minElement = min_element(&data[0], &data[0] + size);
            if (minElement != nullptr) {
                const int indexOfMinElement = minElement - data;
                if (indexOfMinElement >= 0 && indexOfMinElement < size) {
                    data[indexOfMinElement] = val;
                    heapify_up(indexOfMinElement);
                } else {
                    cout << "error\n";
                }
            }
        }
        isUpdated = true;
    }
};

int main()
{
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        //MaxHeap h(k);


        vector<int> heap(k);
        int j = 0;
        for (; j < k; j++)
            heap[j] = arr[j];

        make_heap(heap.begin(), heap.end());

        vector<int>::iterator minPos = min_element(heap.begin(), heap.end());

        for (; j < n; j++) {
            if (heap[0] < arr[j] || arr[j] > *minPos) {
                //need to replace smallest value in the heap with new value
                *minPos = arr[j];
                make_heap(heap.begin(), heap.end());
                minPos = min_element(heap.begin(), heap.end());
            }
        }

        for (j = 0; j < k; j++) {
            cout << heap[0] << " ";
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }

        cout << endl;
    }
    return 0;
}