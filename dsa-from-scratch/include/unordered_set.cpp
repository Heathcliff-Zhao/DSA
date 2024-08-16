#include<iostream>
#include<vector>
#include<list>

template<typename T>
class UnorderedSet {
private:
    static const size_t BUCKET_COUNT = 10;
    std::vector<std::list<T>> table;

    size_t hashFunction(const T& value) const {
        return std::hash<T>{}(value) % BUCKET_COUNT;
    }

public:
    UnorderedSet() : table(BUCKET_COUNT) {}

    void insert(const T& value) {
        size_t hash = hashFunction(value);
        for (const auto& val : table[hash]) {
            if (val == value) {
                return;
            }
        }
        table[hash].push_back(value);
    }

    bool find(const T& value) const {
        size_t hash = hashFunction(value);
        for (const auto& val : table[hash]) {
            if (val == value) {
                return true;
            }
        }
        return false;
    }

    void print() const {
        for (size_t i = 0; i < BUCKET_COUNT; i++) {
            std::cout << "BUCKET " << i << ": ";
            for (const auto& val : table[i]) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    UnorderedSet<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(15);
    mySet.insert(5);

    std::cout << "UnorderedSet contents: " << std::endl;
    mySet.print();

    if (mySet.find(10)) {
        std::cout << "Found value 10 in the set." << std::endl;
    }

    return 0;
}