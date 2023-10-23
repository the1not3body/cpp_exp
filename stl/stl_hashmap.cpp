#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename key, typename value>
class HashMap {
private:
    std::vector<std::list<std::pair<key, value>>> _data;
    size_t _size;
    size_t _capacity;

    size_t Hash(const key& k) {
        return std::hash<key>{}(k) % _capacity;
    }

public:
    HashMap() : _size(0), _capacity(10) {
        _data.resize(_capacity);
    }

    void insert(const key & k, const value & v) {
        size_t index = Hash(k);
        for (auto& pair : _data[index]) {
            if (pair.first == k) {
                pair.second = v;
                return;
            }
        }
        _data[index].push_back(std::make_pair(k, v));
    }

    bool count(const key & k) {
        size_t index = Hash(k);
        for (const auto& pair : _data[index]) {
            if (pair.first == k) {
                return true;
            }
        }
        return false;
    }

    bool erase(const key & k) {
        size_t index = Hash(k);
        for (auto it = _data[index].begin(); it != _data[index].end(); ++it) {
            if (it->first == k) {
                _data[index].erase(it);
                return true;
            }
        }
        return false;
    }

    value& operator[](const key & k) {
        size_t index = Hash(k);
        for (auto& pair : _data[index]) {
            if (pair.first == k) {
                return pair.second;
            }
        }
        _data[index].push_back(std::make_pair(k, value()));
        return _data[index].back().second;
    }

    // const value operator[]=(const key & k, const value & v) {
    //     insert(k, v);
    //     return v;
    // }
};

void Test() {
    HashMap<std::string, int> m;
    m["sss"] = 1;
    std::cout << m["hello"] << std::endl;
    std::cout << m["sss"] << std::endl;
}

int main() {
    Test();

    return 0;
}