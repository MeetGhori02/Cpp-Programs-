#include <iostream>
#include <vector>

using namespace std;

class Employee
{
    string name;
    int salary;
    int bonus_amount;

public:
    Employee() {};
    Employee(string Ename, int Salary, int bonus_amount = 1000)
    {
        name = Ename;
        salary = Salary;
        bonus_amount = bonus_amount;
    }

    int calculatesalary()
    {
        return salary + bonus_amount;
    }

    void getdata()
    {
        cin.ignore();
        cout << "Enter your name : ";
        getline(cin,name);
        cout<<"\n";
        cout << "Enter basic salary : ";
        cin >> salary;
        cout<<"\n";
        cout << "Enter bonus : ";
        cin >> bonus_amount;
        cout<<"\n";
    }

    void putdata()
    {
        cout << "Your name is " << name;
        cout<<"\n";
        cout << "Your basic salary is : " << salary;
        cout<<"\n";
        cout << "Bonus" << bonus_amount;
        cout<<"\n";
        cout << "Total salary is " << calculatesalary();
        cout<<"\n";
    }
};

int main()

{
    int N;
    cout<<"How many employee do you want to add : ";
    cin>>N;
    vector<Employee> Emp;

    //*Emp.push_back(Employee("Meet", 500000));
    //cout<<"\n";
    //Emp.push_back(Employee("Dharm", 1000000));
    //cout<<"\n";
    //Emp.push_back(Employee("Joy", 100000));

    //for (auto &i : Emp)
    for (int i=0; i<N; i++)
    {
        cout<<"Enter employee "<<i+1<<"detail : ";
        Employee T;
        T.getdata();
        Emp.push_back(T);
    }

    for (auto &i : Emp)
    {
        i.putdata();
    }

        return 0;

}
