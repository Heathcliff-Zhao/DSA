#ifndef QUEUE_H
#define QUEUE_H

#include"list.h"

template<typename T>
class Queue {
private:
    List<T> data_;

public:
    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        if (!data_.empty()) data_.pop_front();
    }

    T& front() {
        if (data_.empty()) throw std::out_of_range("Queue is empty");
        return data_.begin()->data;
    }

    T& back() {
        if (data_.empty()) throw std::out_of_range("Queue is empty");
        return data_.end()->data;
    }

    bool empty() const {
        return data_.empty();
    }

    size_t size() const {
        size_t count = 0;
        for (auto current = data_.head_; current != nullptr; current = current->next) count++;
        return count;
    }

};

#endif