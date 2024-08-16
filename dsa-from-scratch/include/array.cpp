#include<iostream>
#include<stdexcept>

template<typename T, size_t N>
class Array {
private:
    T data[N];

public:
    T& operator[](size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t size() const {
        return N;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + N;
    }
};

int main() {
    Array<int, 5> arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = i * 10;
    }

    std::cout << "Array contents: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}