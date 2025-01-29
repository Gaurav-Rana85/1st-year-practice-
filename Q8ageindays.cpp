#include <iostream>
using namespace std;

int main() {
    string name;
    int age;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    int ageInDays = age * 365;
    cout << "Hello " << name << ",you are approximately,  " << ageInDays << " days old!" << endl;
    return 0;
}