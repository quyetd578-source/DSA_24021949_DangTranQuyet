#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class PriorityQueue {
private:
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    // Shift up node at index i to maintain Max-Heap property
    void shiftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // Shift down node at index i to maintain Max-Heap property
    void shiftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heap.size() && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        int r = rightChild(i);
        if (r < heap.size() && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            shiftDown(maxIndex);
        }
    }

public:
    // Check if priority queue is empty
    bool empty() const {
        return heap.empty();
    }

    // Return the size of the priority queue
    size_t size() const {
        return heap.size();
    }

    // Insert a new key into the priority queue
    void push(int key) {
        heap.push_back(key);
        shiftUp(heap.size() - 1);
    }

    // Return element with maximum priority
    int top() const {
        if (heap.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        return heap[0];
    }

    // Remove element with maximum priority
    void pop() {
        if (heap.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        shiftDown(0);
    }
};

int main() {
    PriorityQueue pq;

    // Inserting elements
    pq.push(45);
    pq.push(20);
    pq.push(14);
    pq.push(12);
    pq.push(31);
    pq.push(7);
    pq.push(11);
    pq.push(13);

    std::cout << "Top element (Max Priority): " << pq.top() << "\n";

    std::cout << "Extracting elements in order of priority:\n";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}
