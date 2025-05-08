#include <iostream>
#include <vector>

using namespace std;

class Complex
{
public:
    double real, imaginary;

    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    Complex operator+(const Complex &c) const
    {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex operator-(const Complex &c) const
    {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter real and imaginary part: ";
        in >> c.real >> c.imaginary;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.real << " + " << c.imaginary << "i";
        return out;
    }
};

int main()
{
    int n;
    cout << "How many complex numbers do you want to add: ";
    cin >> n;

    vector<Complex> numbers(n);
    cout << "Enter complex numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    Complex sum(0, 0);
    for (const auto &num : numbers)
    {
        sum = sum + num;
    }

    cout << "Sum of complex numbers: " << sum << endl;

    Complex difference = numbers[0];
    for (int i = 1; i < n; i++)
    {
        difference = difference - numbers[i];
    }

    cout << "Difference of complex numbers: " << difference << endl;

    return 0;
}
