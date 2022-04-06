#include <iostream>

using namespace std;

int main () {
    int *x = nullptr;
    int m = 10;
    x = &m; // x是一个int指针，指向m所在内存的地址

    // *x表示取得地址对应的值，改变*x实际上就是操作m对应的值，这里就改变了m的值
    *x = 12;
    cout << "m = " << m << endl;
    cout << "x = " << x << endl;
}
