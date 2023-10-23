#include <iostream>
#include <cstring>

class String {
private:
    char *m_data;
public:
    String(const char *str = nullptr) {
        if (str == nullptr) {
            m_data = new char[1];
            *m_data = '\0';
        } else {
            int length = strlen(str);
            m_data = new char[length + 1];
            strcpy(m_data, str);
        }
    }
    
    String(const String &other) {
        int length = strlen(other.m_data);
        m_data = new char[length + 1];
        strcpy(m_data, other.m_data);
    } // 拷贝构造函数
    // String(String &&other); // 移动构造函数
    
    String& operator=(const String &other) {
        if (this == &other) {
            return *this; // 检查自赋值
        }
        delete[] m_data;

        int length = strlen(other.m_data);
        m_data = new char[length + 1];
        strcpy(m_data, other.m_data);
        
        return *this;
    } // 拷贝赋值函数
    ~String() {
        delete[] m_data;
    }
    char* c_str() const { return m_data; }
};


void Test() {
    String s1("hello");
    String s2(s1);
    String s3;
    s3 = s2;
    std::cout << s1.c_str() << std::endl;
    std::cout << s2.c_str() << std::endl;
    std::cout << s3.c_str() << std::endl;
}

int main() {
    Test();
    
    return 0;
}