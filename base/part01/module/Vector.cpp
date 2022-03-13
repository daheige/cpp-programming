#include "Vector.h" // 引入header头

// 通过列式的方式进行参数初始化操作
// 构造方法实现
Vector::Vector (int s) : elem{
        new double[s] // 初始化elem
}, sz{s} {}

// 重载操作符号[]
double &Vector::operator[] (int i) { return elem[i]; }

// size方法实现
int Vector::size () {
    return sz;
}
