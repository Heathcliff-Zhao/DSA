#include<iostream>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    T top() const {
        if (topNode) {
            return topNode->data;
        }
        throw std::out_of_range("Stack is empty");
    }

    bool empty() const {
        return topNode == nullptr;
    }
};

int main() {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top() << std::endl;
    myStack.pop();
    std::cout << "After pop, top element: " << myStack.top() << std::endl;

    return 0;
}