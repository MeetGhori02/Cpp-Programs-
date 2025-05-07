#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class Fahrenheit;

class Celsius
{
private:
    double temp;

public:
    Celsius(double t = 0) : temp(t) {}

    operator Fahrenheit();

    bool operator==(const Celsius &other) const
    {
        return fabs(temp - other.temp) < 1e-6;
    }

    void display() const
    {
        cout << temp << " °C";
    }
};

class Fahrenheit
{
private:
    double temp;

public:
    Fahrenheit(double t = 0) : temp(t) {}

    operator Celsius()
    {
        return Celsius((temp - 32) * 5 / 9);
    }

    bool operator==(const Fahrenheit &other) const
    {
        return fabs(temp - other.temp) < 1e-6;
    }

    void display() const
    {
        cout << temp << " °F";
    }
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit(temp * 9 / 5 + 32);
}

int main()
{
    Celsius c1(25), c2(30);
    Fahrenheit f1 = c1;
    Celsius c3 = f1;

    cout << "Celsius to Fahrenheit: ";
    c1.display();
    cout << " = ";
    f1.display();
    cout << "\n";

    cout << "Fahrenheit to Celsius: ";
    f1.display();
    cout << " = ";
    c3.display();
    cout << "\n";

    if (c1 == c2)
    {
        cout << "Temperatures are equal.\n";
    }
    else
    {
        cout << "Temperatures are not equal.\n";
    }

    queue<Fahrenheit> tempQueue;
    tempQueue.push(f1);
    tempQueue.push(Fahrenheit(100));

    cout << "\nTemperatures in queue:\n";
    while (!tempQueue.empty())
    {
        Fahrenheit temp = tempQueue.front();
        temp.display();
        cout << "\n";
        tempQueue.pop();
    }

    return 0;
}

