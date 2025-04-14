#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:

    Person(string n, int a) : name(n), age(a) {}

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};


class Employee : public Person
{   

protected:
    int empID;
    string position;
    double salary;

public:

    Employee(string n, int a, int id, string pos, double sal) : Person(n, a), empID(id), position(pos), salary(sal) {}

    void display()
    {
        Person::display();
        cout << "Employee ID: " << empID << ", Position: " << position << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee
{
protected:
    string department;
    vector<int> teamMembers; // List of employee IDs under this manager

public:

    Manager(string n, int a, int id, string pos, double sal, string dept) : Employee(n, a, id, pos, sal), department(dept) {}

    void addTeamMember(int empID)
    {
        teamMembers.push_back(empID);
    }

    void display()
    {
        Employee::display();
        cout << "Department: " << department << ", Team Members: ";
        for (int id : teamMembers)
        {
            cout << id << " ";
        }
        cout << endl;
    }
};


int main()
{
    Manager m1("Alice", 35, 101, "Senior Manager", 80000, "Sales");
    m1.addTeamMember(201);
    m1.addTeamMember(202);

    m1.display();

    Manager m2("Bob", 40, 102, "Manager", 70000, "Marketing");
    m2.addTeamMember(203);
    m2.addTeamMember(204);

    m2.display();

    return 0;
}


