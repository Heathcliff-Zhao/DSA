#include <iostream>
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "map.h"
#include "algorithm.h"

int main() {
    // Test Vector
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Test List
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    std::cout << "List elements after pushing back: ";
    for (List<int>::Node* node = lst.begin(); node != lst.end(); node = node->next) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    // Test Stack
    Stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << "Stack top element: " << stk.top() << std::endl;
    stk.pop();
    std::cout << "Stack top element after pop: " << stk.top() << std::endl;

    // Test Queue
    Queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    std::cout << "Queue front element: " << que.front() << std::endl;
    que.pop();
    std::cout << "Queue front element after pop: " << que.front() << std::endl;

    // Test Map
    Map<std::string, int> mp;
    mp.insert("one", 1);
    mp.insert("two", 2);
    mp.insert("three", 3);
    std::cout << "Map element with key 'two': " << *mp.find("two") << std::endl;
    mp.erase("two");
    std::cout << "Map element with key 'two' after erase: " << (mp.find("two") == nullptr ? "not found" : "found") << std::endl;

    // Test Algorithm
    Vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(9);
    bubble_sort(arr);
    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    size_t index = binary_search(arr, 4);
    std::cout << "Index of 4 in sorted array: " << (index != arr.size() ? std::to_string(index) : "not found") << std::endl;

    return 0;
}
