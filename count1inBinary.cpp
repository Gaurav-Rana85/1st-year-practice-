#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    int count = 0;
    while (a > 0) {
        count += a & 1;
        a = a >> 1;
        //int count = __builtin_popcount(a); // This line can be used instead of the while loop.
    }

    cout << "The number of 1s in the binary representation is: " << count << endl;

    return 0;
}