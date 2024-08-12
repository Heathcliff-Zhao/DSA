#ifndef MAP_H
#define MAP_H

#include "list.h"
#include "vector.h"
#include <utility>
#include <functional>

template<typename Key, typename Value>
class Map {
public:
    Map(size_t bucketCount = 16) : buckets_(bucketCount) {}

    void insert(const Key& key, const Value& value) {
        size_t index = hash(key) % buckets_.size();
        List<std::pair<Key, Value>>& bucket = buckets_[index];
        for (auto node = bucket.begin(); node != bucket.end(); node = node->next) {
            if (node->data.first == key) {
                node->data.second = value;
                return;
            }
        }
        bucket.push_back(std::make_pair(key, value));
    }

    bool erase(const Key& key) {
        size_t index = hash(key) % buckets_.size();
        List<std::pair<Key, Value>>& bucket = buckets_[index];
        for (auto node = bucket.begin(); node != bucket.end(); node = node->next) {
            if (node->data.first == key) {
                bucket.remove(node);
                return true;
            }
        }
        return false;
    }

    Value* find(const Key& key) {
        size_t index = hash(key) % buckets_.size();
        List<std::pair<Key, Value>>& bucket = buckets_[index];
        for (auto node = bucket.begin(); node != bucket.end(); node = node->next) {
            if (node->data.first == key) {
                return &node->data.second;
            }
        }
        return nullptr;
    }

    bool empty() const {
        for (size_t i = 0; i < buckets_.size(); ++i) {
            if (!buckets_[i].empty()) {
                return false;
            }
        }
        return true;
    }

    size_t size() const {
        size_t count = 0;
        for (size_t i = 0; i < buckets_.size(); ++i) {
            for (auto node = buckets_[i].begin(); node != buckets_[i].end(); node = node->next) {
                ++count;
            }
        }
        return count;
    }

private:
    Vector<List<std::pair<Key, Value>>> buckets_;

    size_t hash(const Key& key) const {
        return std::hash<Key>{}(key);
    }
};

#endif
