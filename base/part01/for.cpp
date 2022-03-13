#include <iostream>
using namespace std;

void copy_fct(){
    int v1[10]= {0,1,2,3,4,5,6,7,8,9};
    int v2[10]; // 声明一个数组，用于存放v1的每个元素

    // 把v1的每个元素赋值给v2的每一项
    for (auto i = 0;i!=10;++i){
        v2[i] = v1[i];
    }

    for(auto i = 0;i<10;i++){
        cout <<"current i = "<< i << endl;
    }

    cout << "=========range for==============" << endl;
    // 范围for语句
    for(auto x:v2){
        cout << "current x = "<< x<< endl;
    }
}

void increment(){
    int v[] = {0,1,2,3,4,5,6,7,8,9}; // 定义数组，没有指定长度，会自动推断个数
    for(auto &x:v) { // 这里是取得x的地址，也就是v数组的每个元素的地址
        ++x;
    }

    for(auto x : v){
        cout << "current x = "<< x << endl;
    }
}

int main(){
    copy_fct();

    cout << "=============increment num=========="<< endl;
    increment();

}
