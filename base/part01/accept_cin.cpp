#include <iostream>

using namespace std;

bool accept2 () {
    cout << "do you want to proceed (y or n)?\n";
    char answer = 0;
    cin >> answer; // 读取用户输入的字符
    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "i will take that for a no.\n";
            return false;
    }
}

bool accept3 () {
    int tries = 1;
    // 循环输入判断
    while (tries < 4) {
        cout << "do you want to proceed (y or n)?\n";
        char answer = 0;
        cin >> answer; // 读取用户输入的字符
        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                ++tries;
        }
    }

    cout << "i will take that for a no.\n";
    return false;
}

int main () {
    bool b = accept2();
    cout << "accept2 result: " << b << "\n";
    bool c = accept3();
    cout << "accept3 result: " << c << "\n";
}

