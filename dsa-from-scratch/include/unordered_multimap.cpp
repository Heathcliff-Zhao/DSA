#include <iostream>
#include <vector>
#include <list>
#include <utility>

template<typename Key, typename Value>
class UnorderedMultiMap {
private:
    static const size_t BUCKET_COUNT = 10;
    std::vector<std::list<std::pair<Key, Value>>> table;

    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % BUCKET_COUNT;
    }

public:
    UnorderedMultiMap() : table(BUCKET_COUNT) {}

    void insert(const Key& key, const Value& value) {
        size_t hash = hashFunction(key);
        table[hash].emplace_back(key, value);
    }

    void print() const {
        for (size_t i = 0; i < BUCKET_COUNT; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& kv : table[i]) {
                std::cout << "(" << kv.first << ", " << kv.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    UnorderedMultiMap<int, std::string> myMultiMap;
    myMultiMap.insert(10, "Ten");
    myMultiMap.insert(20, "Twenty");
    myMultiMap.insert(10, "Another Ten");
    myMultiMap.insert(5, "Five");

    std::cout << "UnorderedMultiMap contents: " << std::endl;
    myMultiMap.print();

    return 0;
}
