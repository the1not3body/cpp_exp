#include <iostream>

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class MyList {
public:
    class Iterator {
    private:
        ListNode<T>* current;

    public:
        Iterator(ListNode<T>* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return current != other.current;
        }
    };

private:
    ListNode<T>* head;

public:
    MyList() : head(nullptr) {}

    void push_back(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (!head) {
            head = newNode;
        } else {
            ListNode<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

int main() {
    MyList<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "List contents using iterator:" << std::endl;
    for (MyList<int>::Iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
