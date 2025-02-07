#include <iostream>
using namespace std;

int main() {
    float p, r, t;
    cout<<"Enter Princile Amount:-";
    cin>>p;
    cout<<"enter rate if intrest:-";
    cin>>r;
    cout<<"Enter Time in years:-";
    cin>>t;
    float si=(p*r*t)/100;
    cout<<"Simple Intrest is:-"<<si;
    return 0;
}