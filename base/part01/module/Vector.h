// 类Vector接口的声明放在header头中
class Vector {
public:
    Vector (int s);

    double &operator[] (int i);

    int size ();

private:
    double *elem;
    int sz;
};
