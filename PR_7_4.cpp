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

ostream &columnWidth(ostream &os)
{
    return os << left << setw(20);
}

void displayHeader()
{
    cout << columnWidth << "Name" << columnWidth << "Marks" << columnWidth << "Grade" << endl;
    cout << string(60, '-') << endl;
}

void displayStudent(const Student &student)
{
    cout << columnWidth << student.name
         << columnWidth << student.marks
         << columnWidth << student.grade
         << endl;
}

void generateReport(const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Unable to open file '" << filename << "'." << endl;
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
    for (const auto &student : students)
    {
        displayStudent(student);
    }
}

int main()
{
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);
    generateReport(filename);
    cout << "Report generated successfully." << endl;
    return 0;
}