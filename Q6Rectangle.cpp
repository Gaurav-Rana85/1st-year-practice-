#include <iostream>
using namespace std;

int main() {
    float l, b;
    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;
    cout<<"Area of reactangle is:-"<<l*b<<"\n";
    cout<<"Perimeter of reactangle is:-"<<2*(l+b);
    return 0;
}