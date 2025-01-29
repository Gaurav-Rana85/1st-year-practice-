#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float p, r, t;
    cout<<"Enter Princile Amount:-";
    cin>>p;
    cout<<"enter rate if intrest:-";
    cin>>r;
    cout<<"Enter Time in years:-";
    cin>>t;
    float ci=p*(pow((1+r/100),t))-p;
    cout<<"Compound Intrest is:-"<<ci;
    return 0;
}