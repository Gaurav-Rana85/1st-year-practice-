#include <iostream>
using namespace std;

int main() {
    int a,b,temp;
    cout<<"Enter two numbers:-";
    cin>>a>>b;
    cout<<"Before Swapping:-"<<a<<" , "<<b<<"\n";
    temp=0;
    temp=a;
    a=b;
    b=temp;
    cout<<"After Swapping:- "<<a<<" , "<<b;
    return 0;
}