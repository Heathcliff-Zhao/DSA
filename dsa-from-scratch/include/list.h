#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

private:
    Node* head_;
    Node* tail_;

public:
    List() : head_(nullptr), tail_(nullptr) {}

    void pop_front() {
        if (head_) {
            Node* toDelete = head_;
            head_ = head_->next;
            if (head_) head_->prev = nullptr;
            else tail_ = nullptr;
            delete toDelete;
        }
    }

    ~List() {
        while (head_) pop_front();
    }

    bool empty() const {
        return head_ == nullptr;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (tail_) {
            tail_->next = newNode;
            newNode->prev = tail_;
            tail_ = newNode;
        }
        else {
            head_ = newNode;
            tail_ = newNode;
        }
    }

    void pop_back() {
        if (tail_) {
            Node* toDelete = tail_;
            tail_ = tail_->prev;
            if (tail_) tail_->next = nullptr;
            else head_ = nullptr;
            delete toDelete;
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (head_) {
            head_->prev = newNode;
            newNode->next = head_;
            head_ = newNode;
        }
        else {
            head_ = newNode;
            tail_ = newNode;
        }
    }

    void erase(Node* node) {
        if (node) {
            if (node->prev) node->prev->next = node->next;
            else head_ = node->next;
            if (node->next) node->next->prev = node->prev;
            else tail_ = node->prev;
            delete node;
        }
    }

    Node* begin() {
        return head_;
    }

    Node* end() {
        return nullptr;
    }

    void remove(Node* node) {
        if (node) {
            if (node->prev) node->prev->next = node->next;
            else head_ = node->next;
            if (node->next) node->next->prev = node->prev;
            else tail_ = node->prev;
            delete node;
        }
    }

};

#endif