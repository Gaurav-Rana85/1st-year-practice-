#include <iostream>
using namespace std;

int main() {
    //5/2->2 beacuse both are integers.
    //5.0/2->2.5 beacuse 5.0 is float and 2 is integer.
    cout<<5/2<<endl;//2
    cout<<5.0/2<<endl;//2.5
    cout<<5/2.0<<endl;//2.5
    cout<<5.0/2.0<<endl;//2.5
    return 0;
}