#include <iostream>
using namespace std;

class Vector{
    private:
        double* elem;
        int sz;
    public:
        // 构造函数
        Vector(int s) : elem{new double[s]},sz{s}{
            for(auto i = 0;i != s;++i){
                elem[i]= 0; // 初始化elem 指针数组
            }
        }

        // 析构函数，做一些数据的清理 
        // 当类的实例不再使用的时候，就会自动调用这个析构函数
        // 在析构函数中释放资源的技术称作为资源获取即初始化 RAII
        // 避免了我们裸new操作的风险，同时避免了裸delete操作，避免了资源泄漏的风险
        ~Vector() { 
            cout << "~ action run" << endl;
            delete[] elem;
        }
        double& operator[](int i);
        int size() const;
};


double& Vector::operator[](int i){ return elem[i];}
int Vector::size() const {
    return sz;
}

int main(){
    Vector v(3);
    for (auto i = 0;i != v.size();++i){
        v[i] = i +1;
    }
    
    for (auto i = 0;i<v.size();i++){
        cout << "current i "<< v[i] << endl;
    }

}

