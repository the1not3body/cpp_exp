#include <iostream>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
public:
    Vector() : _data(nullptr), _size(0), _capacity(10) {
        _data = new T[_capacity];
    }

    // 拷贝构造函数
    

    ~Vector() {
        delete[] _data;
    }
    void push_back(const T& value) {
        if (_size == _capacity) {
            _capacity *= 2;
            T* new_data = new T[_capacity];
            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = _data[i];
            }
            delete[] _data;
            _data = new_data;
        }
        _data[_size++] = value;
    }

    size_t size() const {
        return _size;
    }

    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }
};

void Test() {
    Vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    Test();

    return 0;
}