#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;


struct Account {
    string name;
    int pin;
    double balance;
};


void showMenu();
void checkBalance(const Account& account);
void withdraw(Account& account);
void deposit(Account& account);
void changePin(Account& account);

int main() {
    
    Account account = {"John Doe", 9450, 6000.00};

    int inputPin;
    cout << "Welcome to the ATM!" << endl;
    cout << "Please enter your 4-digit PIN: ";
    cin >> inputPin;

    if (inputPin != account.pin) {
        cout << "Invalid PIN. Access denied." << endl;
        return 1;
    }

    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(account);
                break;
            case 2:
                withdraw(account);
                break;
            case 3:
                deposit(account);
                break;
            case 4:
                changePin(account);
                break;
            case 5:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

void showMenu() {
    cout << "\n--- ATM Menu ---" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Withdraw Cash" << endl;
    cout << "3. Deposit Cash" << endl;
    cout << "4. Change PIN" << endl;
    cout << "5. Exit" << endl;
}

void checkBalance(const Account& account) {
    cout << fixed << setprecision(2); 
    cout << "Your current balance is: $" << account.balance << endl;
}

void withdraw(Account& account) {
    double amount;
    cout << "Enter the amount to withdraw: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Transaction cancelled." << endl;
    } else if (amount > account.balance) {
        cout << "Insufficient balance. Transaction cancelled." << endl;
    } else { 
        account.balance -= amount;
        cout << "Please collect your cash. Your new balance is: $" << account.balance << endl;
    }
}

void deposit(Account& account) {
    double amount;
    cout << "Enter the amount to deposit: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Transaction cancelled." << endl;
    } else {
        account.balance += amount;
        cout << "Deposit successful. Your new balance is: $" << account.balance << endl;
    }
}

void changePin(Account& account) {
    int newPin, confirmPin;
    cout << "Enter your new 4-digit PIN: ";
    cin >> newPin;
    cout << "Confirm your new PIN: ";
    cin >> confirmPin;

    if (newPin == confirmPin) {
        account.pin = newPin;
        cout << "PIN changed successfully." << endl;
    } else {
        cout << "PINs do not match. PIN change failed." << endl;
    }
}
