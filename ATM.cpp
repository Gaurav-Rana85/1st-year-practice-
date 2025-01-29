#include <iostream>
using namespace std;

int main() {
    int choice;
    double balance = 1000.0; // Initial balance
    double amount;

    do {
        cout << "ATM Menu:" << endl;
        cout << "1. Withdrawal" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Balance Inquiry" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient balance!" << endl;
                } else {
                    balance -= amount;
                    cout << "Withdrawal Done. New balance: " << balance << endl;
                }
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                balance += amount;
                cout << "Deposit successful. New balance: " << balance << endl;
                break;
            case 3:
                cout << "Your current balance is: " << balance << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}