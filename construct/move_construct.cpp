#include <iostream>
using namespace std;
 
class demo{
public:
    demo():num(new int(0)){
        cout<<"construct!"<<endl;
    }
 
    demo(const demo &d):num(new int(*d.num)){
        cout<<"copy construct!"<<endl;
    }
 
    //添加移动构造函数
    demo(demo &&d):num(d.num){
        d.num = NULL;
        cout<<"move construct!"<<endl;
    }
 
    ~demo(){
        cout<<"class destruct!"<<endl;
    }
private:
    int *num;
};
 
demo get_demo(){
    return demo();
}
 
int main(){
   class A{
    // virtual ~A() {}
   };
    int *a; //
    cout<<sizeof(a)<<endl;
   cout << sizeof(A) << endl;
    return 0;
}