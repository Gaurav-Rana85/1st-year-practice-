#include <iostream>
using namespace std;

int main() {
    int a,b;
    cout<<"Enter Two Numbers:-";
    cin>>a>>b;
    if (a>b){
        cout<<a<<" is greatest";
    }
    else if(a<b){
        cout<<b<<" is greatest";
    }
    else{
        cout<<"Both are Equal";
    }
    return 0;
}