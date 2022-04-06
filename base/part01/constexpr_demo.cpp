#include <iostream>

using namespace std;

constexpr double C = 199.12;

void f (double speed) {
    const double local_max = 160.0 / (60 * 60);

    // error: static_assert expression is not an integral constant expression
    // static_assert(speed < C,"can not go that fast");
    static_assert(local_max < C, "can not go that fast");

    cout << "static_assert" << endl;
}

int main () {
    f(1.2);
}
