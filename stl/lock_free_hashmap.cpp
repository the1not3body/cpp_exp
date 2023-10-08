#include <iostream>
#include <vector>
#include <atomic>
#include <functional>

const int NUM_BUCKETS = 100;

template <typename Key, typename Value>
class LockFreeHashMap {
public:
    LockFreeHashMap() {
        buckets.resize(NUM_BUCKETS);
    }

    void Insert(const Key& key, const Value& value) {
        size_t hash = std::hash<Key>{}(key);
        size_t bucket_idx = hash % NUM_BUCKETS;

        Bucket& bucket = buckets[bucket_idx];
        Node* new_node = new Node(key, value);

        while (true) {
            Node* head = bucket.head.load();
            new_node->next = head;
            if (bucket.head.compare_exchange_weak(head, new_node)) {
                break;
            }
        }
    }

    bool Get(const Key& key, Value& value) {
        size_t hash = std::hash<Key>{}(key);
        size_t bucket_idx = hash % NUM_BUCKETS;

        Bucket& bucket = buckets[bucket_idx];

        Node* current = bucket.head.load();
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }

        return false;
    }

private:
    struct Node {
        Key key;
        Value value;
        Node* next;

        Node(const Key& k, const Value& v) : key(k), value(v), next(nullptr) {}
    };

    struct Bucket {
        std::atomic<Node*> head;
        Bucket() : head(nullptr) {}
    };

    std::vector<Bucket> buckets;
};

int main() {
    LockFreeHashMap<int, std::string> hashmap;

    hashmap.Insert(1, "One");
    hashmap.Insert(2, "Two");
    hashmap.Insert(3, "Three");

    std::string value;
    if (hashmap.Get(2, value)) {
        std::cout << "Key 2: " << value << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    return 0;
}
