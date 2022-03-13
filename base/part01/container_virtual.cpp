#include <iostream>
#include <list>
using namespace std;

class Vector{
private:
    double* elem;
    int sz;
public:
    // 构造函数
    // double arr[] c语言风格的数组
    Vector(double arr[],int s) : elem{new double[s]},sz{s}{
        for(auto i = 0;i != s;++i){
            elem[i]= arr[i]; // 初始化elem 指针数组
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

// 抽象类定义
// 抽象类型，分离接口和表现形式并且放弃了纯局部变量
// 这个类就是一个纯粹的接口，关键字virtual的意思就是 可以在派生类中重新定义
// virtual声明的函数称作为虚函数
// 派生类负责接口的具体实现
// =0 说明该函数是纯函数，意味着派生类必须定义这个函数
// 含有纯虚函数的类是抽象类
class Container {
public:
    virtual double &operator[] (int) = 0; // 纯虚函数
    virtual int size () const = 0; // 常量成员函数
    // 析构函数是一个虚函数，抽象类需要通过引用或指针来操作
    // 当我们试图通过一个指针销毁Container时，我们并清楚它的实现
    // 到底是哪些资源
    virtual ~Container () {} // 析构函数
};

// 传递是一个是抽象类型进来
// 只需要c是一个接口类型就可以了
void use (Container &c) {
    const int sz = c.size();
    for (auto i = 0; i < sz; i++) {
        cout << c[i] << "\n";
    }
}

// 实现Container抽象类
// :public 派生自 Container抽象类
// 派生类实现基础类,派生类从它的基类继承成员
// 这种关系叫做继承
// 如果类包含虚函数，则该类的每个对象需要一个额外的指针和一个虚函数表
//
// 对于抽象类来说，它的派生类的对象通常是通过抽象基类的接口操纵的，所以基础类中必须有一个虚析构函数
// 当我们使用一个基础类指针释放派生类对象时候，虚函数调用机制能够保证我们调用正确的析构函数
// 然后该析构函数再隐式调用基类的析构函数和成员的析构函数
//
// 类层次提供了2种便利：
// 接口继承：基类是定义接口，派生类像是实现基类
// 实现继承： 基础类负责提供可简化派生类实现的函数或数据
class VectorContainer : public Container {
    Vector v; // 这里是自定义的类型vector实例来实现抽象接口
public:
    VectorContainer (double s[],int sz) : v(s,sz) {} // 含有s个元素的Vector
    ~VectorContainer () {}

    double &operator[] (int i) { return v[i]; }

    int size () const { return v.size(); }
};

// 通过list实现Container抽象接口
class ListContainer : public Container{
    std::list<double> Id;
public:
    ListContainer(){}
    ListContainer(initializer_list<double> il) : Id{il}{}
    ~ListContainer(){}
    double& operator[](int i);
    int size() const { return Id.size();}
};

// ListContainer 实现操作符[]重载
double& ListContainer::operator[](int i){
    for (auto &x:Id){
        if (i == 0){
            return x;
        }

        --i;
    }

    throw out_of_range("list container");
}

void g () {
    double s[] = {1,2,3};
    VectorContainer vc(s,3);
    use(vc);

    cout << "list container" << endl;
    ListContainer lc = {1,2,3,4,5};
    use(lc);
}

int main () {
    g();
}
