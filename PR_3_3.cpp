#include <iostream>
#include <string>
using namespace std;

class accountmanagement
{
    string holname;
    int accnum;
    double balance;

public:
    accountmanagement(string n, int an, double bl)
    {
        holname = n;
        accnum = an;
        balance = bl;
    }

    void deposite(double deposite)
    {
        balance += deposite;
        cout << "You deposited: $" << deposite << endl;
        cout << "Updated balance is: $" << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Oops...You have no sufficient balance" << endl;
            cout << "Your balance is: $" << balance << endl;
        }
        else
        {
            balance -= amount;
            cout << "Updated balance is: $" << balance << endl;
        }
    }

    void getdetails()
    {
        cout << "Account holder name: " << holname << endl;
        cout << "Account number: " << accnum << endl;
        cout << "Current balance is: $" << balance << endl;
    }

    void transfer(accountmanagement &to, double amount)
    {
        if (amount > balance)
        {
            cout << "Oops...You have no sufficient balance" << endl;
            cout << "Your balance is: $" << balance << endl;
        }
        else
        {
            balance -= amount;
            to.balance += amount;
            cout << "Transferred $" << amount << " to account number " << to.accnum << endl;
            cout << "Your updated balance is: $" << balance << endl;
        }
    }
};

int main()
{
    accountmanagement acc1("Meet", 12345, 1000.0);
    accountmanagement acc2("Yug", 67890, 500.0);

    cout << "Details of account 1:" << endl;
    acc1.getdetails();
    cout << endl;

    cout << "Details of account 2:" << endl;
    acc2.getdetails();
    cout << endl;

    cout << "Transferring $500 from account 1 to account 2:" << endl;
    acc1.transfer(acc2, 500);
    cout << endl;

    cout << "Updated details of account 1:" << endl;
    acc1.getdetails();
    cout << endl;

    cout << "Updated details of account 2:" << endl;
    acc2.getdetails();

    return 0;
}