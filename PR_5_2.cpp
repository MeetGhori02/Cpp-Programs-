

#include <iostream>
#include <map>

using namespace std;

class complex
{
public:
    double real, imaginary;
    complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    complex operator+(complex &c)
    {
        return ((real + c.real, imaginary + c.imaginary));
    }

    complex operator-(complex &c)
    {
        return ((real - c.real, imaginary - c.imaginary));
    }
};

int main()
{

    complex c1, c2;
    cout << "How many complex numbers you want to add : ";
    int n;

    cin >> n;
    complex c[n];
    cout << "Enter complex numbers : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter real and imaginary part : ";
        cin >> c[i].real >> c[i].imaginary;
    }

    complex sum(0, 0);
    for (int i = 0; i < n; i++)
    {
        sum = sum + c[i];
    }
    cout << "Sum of complex numbers : " << sum.real << " + " << sum.imaginary << "i" << endl;
    cout << "Subtraction of complex numbers : " << sum.real << " - " << sum.imaginary << "i" << endl;
}