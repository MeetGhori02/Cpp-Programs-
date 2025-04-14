#include <iostream>
#include <vector>

using namespace std;
#define pi 3.141592
using namespace std;

class shape
{
protected:
    double radius;

public:
void getdata()
{
    cout << "Enter radius of circle : " ;
    cin >> radius;
}
};

class circle : public shape
{
public:
    double area()
    {
        return pi * radius * radius;
    }

    void display()
    {
        cout << "Circle with radius " << radius << " has area: " << area() << endl;
    }
};


    void dynamicApproach()
    {
        int n;
        cout << "\nEnter the number of circles : ";
        cin >> n;
    
        vector<circle> circles;
        for (int i = 0; i < n; i++)
        {
            circle temp;
            cout << "Circle " << i + 1 << ":" << endl;
            temp.getdata();
       }
    
        cout << "\nDisplaying Areas :\n";
        for (auto &c : circles)
        {
            c.display();
        }
    }
    
    void staticApproach()
    {
        int SIZE ; 
        cout<< "enter number of circles : " ;
        cin >> SIZE;
        circle circles[SIZE];
    
        cout << "\nEnter data for " << SIZE << " circles:\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Circle " << i + 1 << ":" << endl;
            circles[i].getdata();
        }
        cout << "\nDisplaying Areas :\n";
        for (int i = 0; i < SIZE; i++)
        {
            circles[i].display();
        }
    }
    int main()
    {
        int n;
        cout << "Press\n 1.dynamicApproach\n 2.staticApproch  " << endl;
        cout << "enter number : ";
        cin >> n;
        if(n==1)
            dynamicApproach();
        else
            staticApproach();
    
            return 0;
    }
