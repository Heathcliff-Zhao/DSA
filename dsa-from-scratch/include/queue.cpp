#include <iostream>

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;

public:
    Queue() : frontNode(nullptr), backNode(nullptr) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        if (backNode) {
            backNode->next = newNode;
        }
        backNode = newNode;
        if (!frontNode) {
            frontNode = newNode;
        }
    }

    void pop() {
        if (frontNode) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (!frontNode) {
                backNode = nullptr;
            }
            delete temp;
        }
    }

    T front() const {
        if (frontNode) {
            return frontNode->data;
        }
        throw std::out_of_range("Queue is empty");
    }

    bool empty() const {
        return frontNode == nullptr;
    }
};

int main() {
    Queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Front element: " << myQueue.front() << std::endl;
    myQueue.pop();
    std::cout << "After pop, front element: " << myQueue.front() << std::endl;

    return 0;
}
