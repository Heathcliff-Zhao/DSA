#ifndef STACK_H
#define STACK_H

#include"vector.h"

template<typename T>
class Stack {
private:
    Vector<T> data_;

public:
    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        if (!data_.empty()) data_.pop_back();
    }

    T& top() {
        if (data_.empty()) throw std::out_of_range("Stack is empty");
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        return data_.size();
    }
    
};

#endif