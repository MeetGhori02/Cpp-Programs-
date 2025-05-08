#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Include for string stream usage
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactionHistory;

    void logTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

public:
    BankAccount(const string& name, double initialBalance) : accountHolder(name), balance(initialBalance) {
        std::ostringstream oss;
        oss << initialBalance;
        logTransaction("Account created with balance: " + oss.str());
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::ostringstream oss;
            oss << amount;
            logTransaction("Failed deposit attempt: Invalid amount " + oss.str());
            cout << "Error: Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        std::ostringstream oss;
        oss << amount << ", New balance: " << balance;
        logTransaction("Deposited: " + oss.str());
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::ostringstream oss;
            oss << amount;
            logTransaction("Failed withdrawal attempt: Invalid amount " + oss.str());
            cout << "Error: Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            std::ostringstream oss;
            oss << amount;
            logTransaction("Failed withdrawal attempt: Insufficient funds for amount " + oss.str());
            cout << "Error: Insufficient funds.\n";
            return;
        }
        balance -= amount;
        std::ostringstream oss;
        oss << amount << ", New balance: " << balance;
        logTransaction("Withdrew: " + oss.str());
    }

    void displayBalance() const {
        cout << "Current balance: " << balance << "\n";
    }

    void displayTransactionHistory() const {
        cout << "Transaction History:\n";
        for (const auto& transaction : transactionHistory) {
            cout << transaction << "\n";
        }
    }
};

int main() {
    string name;
    double initialBalance;

    cout << "Enter account holder's name: ";
    cin >> name;
    cout << "Enter initial balance: ";
    while (!(cin >> initialBalance) || initialBalance < 0) {
        cout << "Invalid input. Please enter a non-negative initial balance: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    BankAccount account(name, initialBalance);

    int choice;
    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Display Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        }
        case 2: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        }
        case 3:
            account.displayBalance();
            break;
        case 4:
            account.displayTransactionHistory();
            break;
        case 5:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}