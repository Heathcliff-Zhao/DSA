#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "vector.h"
#include <functional>

template<typename T>
void bubble_sort(Vector<T>& arr, std::function<bool(const T&, const T&)> comp = std::less<T>()) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (comp(arr[j + 1], arr[j])) std::swap(arr[j], arr[j + 1]);
        }
    }
}

template<typename T>
size_t binary_search(const Vector<T>& arr, const T& value) {
    size_t left = 0;
    size_t right = arr.size();
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == value) return mid;
        else if (arr[mid] < value) left = mid + 1;
        else right = mid;
    }
    return arr.size();
}

#endif
