#ifndef VECTOR_H
#define VECTOR_H

#include<stdexcept>

template<typename T>
class Vector {
private:
    size_t size_;
    size_t capacity_;
    T* data_;
    void resize() {
        capacity_ *= 2;
        T* newData = new T[capacity_];
        for (size_t i = 0; i < size_; i++) newData[i] = data_[i];
        delete[] data_;
        data_ = newData;
    }

public:
    Vector() : size_(0), capacity_(1), data_(new T[1]) {}
    Vector(size_t size) : data_(new T[size]), size_(size), capacity_(size) {}

    ~Vector() {delete[] data_;}

    void push_back(const T& value) {
        if (size_ == capacity_) resize();
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ > 0) size_--;
    }

    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& operator[] (size_t index) const {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return !size_;
    }

    T& back() {
        if (size_ == 0) throw std::out_of_range("Vector is empty");
        return data_[size_ - 1];
    }

    T* begin() {
        return data_;
    }

    T* end() {
        return data_ + size_;
    }

};

#endif