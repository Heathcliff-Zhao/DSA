#include<iostream>

template<typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    ForwardList() : head(nullptr) {}

    ~ForwardList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    std::cout << "ForwardList contents: ";
    list.print();

    list.pop_front();
    std::cout << "After pop_front, ForwardList contents: ";
    list.print();

    return 0;
}