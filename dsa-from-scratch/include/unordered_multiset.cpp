#include <iostream>
#include <vector>
#include <list>

template<typename T>
class UnorderedMultiSet {
private:
    static const size_t BUCKET_COUNT = 10;
    std::vector<std::list<T>> table;

    size_t hashFunction(const T& value) const {
        return std::hash<T>{}(value) % BUCKET_COUNT;
    }

public:
    UnorderedMultiSet() : table(BUCKET_COUNT) {}

    void insert(const T& value) {
        size_t hash = hashFunction(value);
        table[hash].push_back(value);
    }

    size_t count(const T& value) const {
        size_t hash = hashFunction(value);
        size_t cnt = 0;
        for (const auto& val : table[hash]) {
            if (val == value) {
                cnt++;
            }
        }
        return cnt;
    }

    void print() const {
        for (size_t i = 0; i < BUCKET_COUNT; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& val : table[i]) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    UnorderedMultiSet<int> myMultiSet;
    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(10);
    myMultiSet.insert(5);

    std::cout << "UnorderedMultiSet contents: " << std::endl;
    myMultiSet.print();

    std::cout << "Count of value 10: " << myMultiSet.count(10) << std::endl;

    return 0;
}
