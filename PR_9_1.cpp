#include <iostream>
#include <limits>
using namespace std;

int main() {
    double loanAmount, annualIncome;

    cout << "Enter the total loan amount: ";
    while (!(cin >> loanAmount) || loanAmount <= 0) {
        cout << "Invalid input. Please enter a positive numerical value for the loan amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter your annual income: ";
    while (!(cin >> annualIncome) || annualIncome <= 0) {
        cout << "Invalid input. Please enter a positive numerical value for the annual income: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double ratio = loanAmount / annualIncome;
    cout << "The loan-to-income ratio is: " << ratio << endl;

    return 0;
}