#include<iostream>
#include<vector>
#include<algorithm>

template<typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        if (index == 0) {
            return;
        }
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    T top() const {
        if (!heap.empty()) {
            return heap.front();
        }
        throw std::out_of_range("PriorityQueue is empty");
    }

    bool empty() const {
        return heap.empty();
    }
};

int main() {
    PriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);

    std::cout << "Top element: " << pq.top() << std::endl;
    pq.pop();
    std::cout << "After pop, top element: " << pq.top() << std::endl;

    return 0;
}