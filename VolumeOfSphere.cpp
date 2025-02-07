#include <iostream>
using namespace std;

int main() {
    float r;
    cout<<"Enter Value of Radius:-";
    cin>>r;
    float volume=4/3*3.14*r*r*r;
    cout<<"Volume of Sphere with Radius "<<r<<" is:-"<<volume;
    return 0;
}