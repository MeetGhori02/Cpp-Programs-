#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point* shiftX(int dx)
    {
        x += dx;
        return this;
    }

    Point* shiftY(int dy)
    {
        y += dy;
        return this;
    }

    Point* shift(int dx, int dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point p(5, 10);

    cout << "Initial Point: ";
    p.display();

    p.shiftX(3)->shiftY(-2)->shift(1, 1);

    cout << "After Shifts: ";
    p.display();

    return 0;
}