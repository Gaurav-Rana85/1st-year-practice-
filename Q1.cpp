#include<iostream>
using namespace std;

int main() {
    string name;
    string age;
    cout << "Enter your name: "<<"\n";
    getline(cin, name);
    cout<< "Enter your age: "<<"\n";
    getline(cin, age);
    cout << "Hello " << name <<",you are "<< age <<" year old! ";
    return 0;
}