#include <iostream>
using namespace std;

enum class Color {red,blue,green};

int main(){
    Color c = Color::red;
    switch(c){
        case Color::red:
            cout << "c is red" << endl;
            break;
        default:
            cout << "c is not red " << endl;
    }
}
