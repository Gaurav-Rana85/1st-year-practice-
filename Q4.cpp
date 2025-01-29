#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    float c = a/b;
    cout << "Remainder is: " << fixed << setprecision(2) << c << endl;
    return 0;
}