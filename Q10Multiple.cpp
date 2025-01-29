#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (a == 0 || b == 0) {
        cout << "Neither number can be zero." << endl;
    } else if ((a % b == 0) || (b % a == 0)) {
        if (a % b == 0) {
            cout << a << " is a multiple of " << b << endl;
        } else {
            cout << b << " is a multiple of " << a << endl;
        }
    } else {
        cout << "Neither number is a multiple of the other." << endl;
    }

    return 0;
}