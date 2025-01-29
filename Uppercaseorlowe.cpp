#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        cout << "The character is uppercase";
    } else if (ch >= 'a' && ch <= 'z') {
        cout << "The character is lowercase";
    } else {
        cout << "The character is not an alphabet letter." << endl;
    }

    return 0;
}