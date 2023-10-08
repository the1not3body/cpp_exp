#include <string>

template <class T>
class NameObject {
public:
    NameObject(std::string& name, const T& value) : nameValue(name), value(objectValue);
private:
    std::string& nameValue;
    const T objectValue;
};



int main() {
    std::string newDog("a");
    std::string oldDog("b");
    NameObject<int> p(newDog, 2);
    NameObject<int> s(oldDog, 36);
    // p = s;
    return 0;    
}