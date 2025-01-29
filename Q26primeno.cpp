#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of prime numbers to print: ";
    cin >> n;
    int count = 0;
    int num = 2;
    while (count < n) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;
    return 0;
}
