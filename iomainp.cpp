#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float number;
    cout << "Enter an integer: ";
    cin >> number;

    cout << "Your number is: " << number << endl;

    cout << "Width 3: [" << setw(10) << number << "]" << endl;

    cout << "Default precision: " << number << endl;
    cout << "Precision 3: " << setprecision(4) << number << endl;

    cout << "Width 10 with fill: [" << setfill('*') << setw(10) << number << "]" << endl;

    cout << "Left aligned: [" << left << setw(10) << number << "]" << endl;

    cout << "Right aligned: [" << right << setw(10) << number << "]" << endl;

    return 0;
}