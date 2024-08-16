#include <iostream>
#include <stdexcept>

template<typename T>
class Deque {
private:
    T* data;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t size;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        size_t j = 0;
        for (size_t i = front, count = 0; count < size; i = (i + 1) % capacity, ++count) {
            newData[j++] = data[i];
        }
        front = 0;
        rear = size;
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Deque() : data(nullptr), capacity(0), front(0), rear(0), size(0) {}

    ~Deque() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        ++size;
    }

    void push_front(const T& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        front = (front == 0 ? capacity - 1 : front - 1);
        data[front] = value;
        ++size;
    }

    void pop_back() {
        if (size > 0) {
            rear = (rear == 0 ? capacity - 1 : rear - 1);
            --size;
        }
    }

    void pop_front() {
        if (size > 0) {
            front = (front + 1) % capacity;
            --size;
        }
    }

    T& getFront() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return data[front];
    }

    T& getBack() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return data[rear == 0 ? capacity - 1 : rear - 1];
    }

    size_t getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void print() const {
        for (size_t i = front, count = 0; count < size; i = (i + 1) % capacity, ++count) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(0);
    deque.push_back(3);

    std::cout << "Deque contents: ";
    deque.print();

    deque.pop_back();
    std::cout << "After pop_back, deque contents: ";
    deque.print();

    deque.pop_front();
    std::cout << "After pop_front, deque contents: ";
    deque.print();

    return 0;
}
