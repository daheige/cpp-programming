#include <iostream>
using namespace std;

struct Vector {
    int sz; // 元素的数量
    double* elem; // 指向double的元素指针
};

// Vector&指向v的内存地址，这里是pass by reference通过引用的方式传递参数
void vector_init(Vector& v,int s){
    v.elem = new double[s]; // 创建一个double类型的数组指针
    v.sz = s;
}

// 读取s个整数，然后求和
double read_and_sum(int s){
    Vector v;
    // 初始化操作
    vector_init(v,s);

    // 循环读取用户输入的数字
    for (auto i = 0;i !=s;++i){
        cin >> v.elem[i];
    }

    // 执行求和
    double sum = 0;
    for (auto i = 0;i!=s;++i){
        sum += v.elem[i];
    }

    return sum;
}


int main(){
    Vector v;
    v.sz = 1;
    v.elem = new double(1); // new动态分配内存在堆上
    cout << "elem = "<< v.elem << endl;

    double sum = read_and_sum(3);
    cout << "sum = "<< sum << endl;

    return 0;
}

/*
 * % ./user-defined-types.out
elem = 0x600000644040
1
2
10
sum = 13
*/

