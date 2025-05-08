#include <iostream>
#include <stack>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() const
    {
        return Point(-x, -y);
    }

    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")";
    }
};

int main()
{
    stack<Point> operationStack;

    Point p1(3, 4), p2(-1, 2);
    Point p3 = p1 + p2;

    operationStack.push(p1);
    operationStack.push(p2);
    operationStack.push(p3);

    cout << "Initial Points and Operations:\n";
    cout << "Point 1: ";
    p1.display();
    cout << "\nPoint 2: ";
    p2.display();
    cout << "\nPoint 3 (Point 1 + Point 2): ";
    p3.display();
    cout << "\n\n";

    cout << "Undoing operations:\n";
    while (!operationStack.empty())
    {
        Point top = operationStack.top();
        top.display();
        cout << "\n";
        operationStack.pop();
    }

    return 0;
}
