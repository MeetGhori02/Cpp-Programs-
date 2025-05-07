#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;
    int marks;
    char grade;
};

void displayHeader()
{
    cout << left << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << endl;
    cout << string(40, '-') << endl;
}

void displayStudent(const Student& student)
{
    cout << left << setw(20) << student.name << setw(10) << student.marks << setw(10) << student.grade << endl;
}

void generateReport(const string& filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    vector<Student> students;
    string name;
    int marks;
    char grade;

    while (file >> ws && getline(file, name, ',') && file >> marks >> grade)
    {
        students.push_back({name, marks, grade});
    }
    file.close();

    displayHeader();
    for (const auto& student : students)
    {
        displayStudent(student);
    }
}

int main()
{
    string filename = "students.txt";
    generateReport(filename);
    return 0;
}