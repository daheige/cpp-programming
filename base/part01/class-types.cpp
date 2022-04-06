#include <iostream>

using namespace std;

class Vector {
public:
    // 构造函数Vector必须和类名一样
    // :elem{}通过成员初始化列表来初始化class类成员
    Vector (int s) : elem{
            new double[s] // 初始化elem元素
    }, sz{s} {

    }

    // 函数返回值是double& 是一个指向double类型的指针
    // operator[]表示操作符号[]重载实现
    double &operator[] (int i) { return elem[i]; }

    // 通过下标访问元素，这里是重载类操作符号[i]
    int size () { return sz; }

private:
    double *elem; // 指向元素的指针
    int sz; // 元素的数量
};

double read_and_sum (int s) {
    Vector v(s); // 初始化一个实例对象v
    cout << "please input " << s << " size number and enter" << endl;
    for (auto i = 0; i != v.size(); ++i) {
        cin >> v[i]; // 读取输入的元素
    }

    double sum = 0;
    for (auto i = 0; i != v.size(); ++i) {
        sum += v[i];
    }

    return sum;
}

int main () {
    double sum = read_and_sum(3);

    cout << "sum = " << sum << endl;
    return 0;
}

