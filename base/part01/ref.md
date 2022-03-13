# 声明运算符
    T a[n] 表示n个T类型的数组，用变量a表示
    T* p // T*: 表示指向T的指针
    T & r // T&:T的引用
    T f(A) // T(A) 是一个函数，接收A类型的实参

    我们的目标是确保指针永远指向某个对象，这样解引用该指针的操作是合法的。
    当确实没有对象可值或表达一种“没有可用对象"的含义时候，用空指针 nullptr

# 空指针定义
比如：
``` c++
    double* pd = nullptr;
    Link<Record>* lst = nullptr; // 执行一个Record的Link的指针
    int* x = nullptr;
```
取地址和修改值
```c++ 
//ref.cpp
#include <iostream>
using namespace std;

int main(){
    int* x = nullptr;
    int m = 10;
    x = &m; // x是一个int指针，指向m所在内存的地址

    // *x表示取得地址对应的值，改变*x实际上就是操作m对应的值，这里就改变了m的值
    *x = 12;
    cout << "m = " << m << endl;
    cout << "x = " << x << endl;
}
```
