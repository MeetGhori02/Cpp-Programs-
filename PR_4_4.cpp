#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct transaction
{
    string type;
    double amount;

    transaction(string t, double a) : type(t), amount(a) {}
};

class BankAccount
{
protected:
    int accno;
    double balance;

public:
    BankAccount(int acno, double bal) : accno(acno), balance(bal) {}

    void Deposite(double amt)
    {
        balance += amt;
        cout << "Deposited : " << balance << endl;
    }

    void withdraw(double amt)
    {
        if (amt > balance)
        {
            cout << "Sorry , Insufficient Balance \n";
        }
        else
        {
            balance -= amt;
            cout << "Withdrawn : " << balance << endl;
        }
    }

    void undo(stack<transaction> &T)
    {
        if (T.empty())
        {
            cout << "No transactions to undo." << endl;
            return;
        }

        transaction lastTransaction = T.top();
        T.pop();

        if (lastTransaction.type == "Deposit")
        {
            balance -= lastTransaction.amount;
            cout << "Undid Deposit of: " << lastTransaction.amount << endl;
            cout << "Balance after undo: " << balance << endl;
        }
        else if (lastTransaction.type == "Withdraw")
        {
            balance += lastTransaction.amount;
            cout << "Undid Withdraw of: " << lastTransaction.amount << endl;
            cout << "Balance after undo: " << balance << endl;
        }
        else
        {
            cout << "Unknown transaction type." << endl;
        }
    }

    double getbalance()
    {
        return balance;
    }
};

class SavingAcc : public BankAccount
{
public:
    SavingAcc() : BankAccount(0, 0) {}
    SavingAcc(int acno, double bal) : BankAccount(acno, bal) {}
};

class currentacc : public BankAccount
{
public:
    currentacc() : BankAccount(0, 0) {}
    double overdraftlimit;
    currentacc(int acno, double bal, double odlimit) : BankAccount(acno, bal), overdraftlimit(odlimit) {}

    void withdraw(double amt)
    {
        if (amt > balance + overdraftlimit)
        {
            cout << "Sorry , Insufficient Balance \n";
        }
        else
        {
            balance -= amt;
            cout << "Withdrawn : " << balance << endl;
        }
    }
};

int main()
{
    int n;
    int acno;
    double Bal;

    cout << "Enter Account type (1 for Saving  or 2 for Current) : ";
    cin >> n;

    cout << "Enter Account Number: ";
    cin >> acno;

    cout << "Enter Initial Balance: ";
    cin >> Bal;

    SavingAcc sav;
    currentacc cur;

    if (n == 1)
    {
        cout << "Saving Account Created" << endl;
        sav = SavingAcc(acno, Bal);
    }
    else if (n == 2)
    {
        double odlimit;
        cout << "Enter Overdraft Limit: ";
        cin >> odlimit;
        cout << "Current Account Created" << endl;
        cur = currentacc(acno, Bal, odlimit);
    }
    else
    {
        cout << "Invalid Account Type" << endl;
        return 1;
    }

    stack<transaction> T;
    cout << "Account Created Successfully" << endl;
    int choice;
    double amt;
    do
    {

        cout << "\n1.Deposit \n2.Withdraw \n3.Undo \n4.Show Balance \n5.Exit";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount you want to Deposit: ";
            cin >> amt;
            if (n == 1)
                sav.Deposite(amt);
            else
                cur.Deposite(amt);
            T.push(transaction("Deposit", amt)); // Store the transaction

            break;

        case 2:
            cout << "Enter amount you want to Withdraw: ";
            cin >> amt;
            if (n == 1)
                sav.withdraw(amt);
            else
                cur.withdraw(amt);
            T.push(transaction("Withdraw", amt)); // Store the transaction
            break;

        case 3:
            if (n == 1)
                sav.undo(T);

            else if (n == 2)

                cur.undo(T);
            break;

        case 4:
            if (n == 1)
                cout << "Your current balance is: " << sav.getbalance() << endl;
            else
                cout << "Your current balance is: " << cur.getbalance() << endl;

            T.push(transaction("Balance", 0)); // Store the transaction
            break;

        case 5:
            cout << "Exiting Program !!!!" << endl;
            break;

        default:
            cout << "Invalid choice !!!" << endl;
        }
    } while (choice != 5);

    return 0;
}
