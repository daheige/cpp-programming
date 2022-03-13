#include <iostream>
using namespace std;


void test(){
    try {
        int x = 1;
        cout << "x / 0 " << x / 0 << endl;
    }catch(exception){
        cout << "except error"<< endl;
    }
}

int main(){
    test();
}
