#include <iostream>
#include "Vector.h" // 导入自定义的header头
#include <cmath> // 表示导入c语言风格的math库

using namespace std;

double sqrt_num (Vector &v) {
    double sum = 0;
    for (auto i = 0; i != v.size(); ++i) {
        sum += sqrt(v[i]); // 调用cmath里面的函数
    }

    return sum;
}

int main () {
    Vector v(3);
    cout << "please 3 size number"<< endl;
    for (auto i = 0; i != v.size(); ++i) {
        cin >> v[i];
    }

    cout << "sum = " << sqrt_num(v) << endl;

    return 0;
}
