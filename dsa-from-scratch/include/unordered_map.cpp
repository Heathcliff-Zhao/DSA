#include<iostream>
#include<vector>
#include<list>

template<typename Key, typename Value>
class UnorderedMap {
private:
    static const size_t BUCKET_COUNT = 10;
    std::vector<std::list<std::pair<Key, Value>>> table;

    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % BUCKET_COUNT;
    }

public:
    UnorderedMap() : table(BUCKET_COUNT) {}

    void insert(const Key& key, const Value& value) {
        size_t hash = hashFunction(key);
        for (auto& kv : table[hash]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        table[hash].emplace_back(key, value);
    }

    bool find(const Key& key, Value& value) const {
        size_t hash = hashFunction(key);
        for (const auto& kv : table[hash]) {
            if (kv.first == key) {
                value = kv.second;
                return true;
            }
        }
        return false;
    }

    void print() const {
        for (size_t i = 0; i < BUCKET_COUNT; i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& kv : table[i]) {
                std::cout << "(" << kv.first << ", " << kv.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    UnorderedMap<int, std::string> myMap;
    myMap.insert(10, "Ten");
    myMap.insert(20, "Twenty");
    myMap.insert(15, "Fifteen");
    myMap.insert(5, "Five");

    std::cout << "UnorderedMap contents: " << std::endl;
    myMap.print();

    std::string value;
    if (myMap.find(10, value)) {
        std::cout << "Found key 10 with value: " << value << std::endl;
    }

    return 0;
}