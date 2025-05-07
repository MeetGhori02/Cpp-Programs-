//THIS CODE IS WRITTEN BY 24CE034-MEET_GHORI
#include <iostream>
#include <vector>
using namespace std;

class Student
{
protected:
    float Marks;

public:
    Student(float M) : Marks(M) {}

    virtual string computergrade() = 0;
};

class UG : public Student
{
public:
    UG(float M) : Student(M) {}

    string computergrade() override
    {
        if (Marks >= 85)
            return "A";
        else if (Marks >= 70)
            return "B";
        else if (Marks >= 50)
            return "C";
        else
            return "F";
    }
};

class PG : public Student
{
public:
    PG(float M) : Student(M) {}
    string computergrade() override
    {
        if (Marks >= 85)
            return "A";
        else if (Marks >= 70)
            return "B";
        else if (Marks >= 50)
            return "C";
        else
            return "F";
    }
};

int main()
{
    vector<Student *> S;

    int n;
    cout << "Enter No. of student : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int level;
        float mark;

        cout << "Enter 1 for UG and 2 for PG : ";
        cin >> level;
        cout << "Enter Mark : 0";
        cin >> mark;

        if (level == 1)
        {
            S.push_back(new UG(mark));
        }
        else if (level == 2)
        {
            S.push_back(new PG(mark));
        }
        else
        {
            cout << "Invalid Input !!!" << endl;
        }
        cout << "Grade : " << S[i]->computergrade() << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete S[i]; 
    }

    S.clear(); 

    cout << "Memory cleared" << endl;

    return 0;
}
