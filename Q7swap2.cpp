#include <iostream>
using namespace std;

int main() {
    int a,b;
    cout<<"Enter two numbers:-";
    cin>>a>>b;
    cout<<"Before Swapping:-"<<a<<" , "<<b<<"\n";
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"After Swapping:- "<<a<<" , "<<b;
    return 0;
}