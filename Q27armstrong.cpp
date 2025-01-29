#include <iostream>
using namespace std;

int main() {
    int a;
    cout<<"Enter a no. to check if it is an Armstrong number: ";
    cin>>a;
    int sum = 0;
    int temp = a;
    while (a > 0) {
        int n = a % 10;
        sum += n * n * n;
        a = a / 10;
    }
    if (sum == temp) {
        cout<<temp<<" is an Armstrong number."<<endl;
    } else {
        cout<<temp<<" is not an Armstrong number."<<endl;
    }
    return 0;
}