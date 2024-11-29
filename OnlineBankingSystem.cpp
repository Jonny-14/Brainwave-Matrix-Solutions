#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

using namespace std;

struct Account {
    string accountHolderName;
    int accountNumber;
    double balance;
};

vector<Account> accounts;

void displayMenu();
void createAccount();
void depositFunds();
void withdrawFunds();
void transferFunds();
Account* findAccount(int accountNumber);

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositFunds();
                break;
            case 3:
                withdrawFunds();
                break;
            case 4:
                transferFunds();
                break;
            case 5:
                cout << "Thank you for using the online banking system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n--- Online Banking System Menu ---" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Funds" << endl;
    cout << "3. Withdraw Funds" << endl;
    cout << "4. Transfer Funds" << endl;
    cout << "5. Exit" << endl;
}

void createAccount() {
    Account newAccount;
    cout << "Enter account holder's name: ";
    cin.ignore();
    getline(cin, newAccount.accountHolderName);

    cout << "Enter initial deposit amount: ";
    cin >> newAccount.balance;

    if (newAccount.balance < 0) {
        cout << "Initial deposit cannot be negative. Account creation failed." << endl;
        return;
    }

    newAccount.accountNumber = accounts.size() + 1; 
    accounts.push_back(newAccount);

    cout << "Account created successfully!" << endl;
    cout << "Account Holder: " << newAccount.accountHolderName << endl;
    cout << "Account Number: " << newAccount.accountNumber << endl;
    cout << "Initial Balance: $" << fixed << setprecision(2) << newAccount.balance << endl;
}

void depositFunds() {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    Account* account = findAccount(accountNumber);

    if (account == nullptr) {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Transaction cancelled." << endl;
        return;
    }

    account->balance += amount;
    cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << account->balance << endl;
}

void withdrawFunds() {
    int accountNumber;
    double amount;

    cout << "Enter account number: ";
    cin >> accountNumber;

    Account* account = findAccount(accountNumber);

    if (account == nullptr) {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Transaction cancelled." << endl;
        return;
    }

    if (amount > account->balance) {
        cout << "Insufficient balance. Transaction cancelled." << endl;
        return;
    }

    account->balance -= amount;
    cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << account->balance << endl;
}

void transferFunds() {
    int senderAccountNumber, receiverAccountNumber;
    double amount;

    cout << "Enter sender's account number: ";
    cin >> senderAccountNumber;

    Account* senderAccount = findAccount(senderAccountNumber);

    if (senderAccount == nullptr) {
        cout << "Sender's account not found." << endl;
        return;
    }

    cout << "Enter receiver's account number: ";
    cin >> receiverAccountNumber;

    Account* receiverAccount = findAccount(receiverAccountNumber);

    if (receiverAccount == nullptr) {
        cout << "Receiver's account not found." << endl;
        return;
    }

    cout << "Enter amount to transfer: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Transaction cancelled." << endl;
        return;
    }

    if (amount > senderAccount->balance) {
        cout << "Insufficient balance in sender's account. Transaction cancelled." << endl;
        return;
    }

    senderAccount->balance -= amount;
    receiverAccount->balance += amount;

    cout << "Transfer successful!" << endl;
    cout << "Sender's new balance: $" << fixed << setprecision(2) << senderAccount->balance << endl;
    cout << "Receiver's new balance: $" << fixed << setprecision(2) << receiverAccount->balance << endl;
}

Account* findAccount(int accountNumber) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}
