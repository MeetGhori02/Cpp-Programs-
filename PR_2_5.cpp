#include <iostream>
#include <cmath>
using namespace std;

class Loan
{
public:
    int loan_id;
    string applicant_name;
    double loan_amount;
    double annual_interest_rate;
    int loan_tenure_months;

    Loan(int id, string name, double amount, double rate, int tenure)
    {
        loan_id = id;
        applicant_name = name;
        loan_amount = amount;
        annual_interest_rate = rate;
        loan_tenure_months = tenure;
    }

    double calculate_emi()
    {
        double monthly_interest_rate = annual_interest_rate / 12 / 100;
        int n = loan_tenure_months;
        return (loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, n)) /
               (pow(1 + monthly_interest_rate, n) - 1);
    }

    void display_loan_details()
    {
        cout << "Loan ID: " << loan_id << endl;
        cout << "Applicant Name: " << applicant_name << endl;
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Annual Interest Rate: " << annual_interest_rate << "%" << endl;
        cout << "Loan Tenure: " << loan_tenure_months << " months" << endl;
        cout << "EMI: " << calculate_emi() << endl;
    }
};

int main()
{
    Loan loan1(101, "Yash", 500000, 8.5, 240);
    Loan loan2(102, "Meet", 300000, 7.5, 180);

    loan1.display_loan_details();
    cout<<endl;
    loan2.display_loan_details();

    return 0;
}
