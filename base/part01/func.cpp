#include <iostream>

using namespace std;

double square (double x) {
    return x * x;
}

// 没有返回值的函数
// void表示函数不返回任何值
void print_square (double x) {
    cout << "the square:" << x << square(x) << "\n";
}

// 对于main如果没有return 0; 默认是返回0
int main () {
    print_square(1.234);
}
