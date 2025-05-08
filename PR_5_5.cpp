#include <iostream>
#include <vector>
using namespace std;

class Rectangle {
public:
    double length, width;
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const {
        return length * width;
    }
};

class Circle {
public:
    double radius;
    Circle(double r) : radius(r) {}
    double Area() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    vector<Rectangle> rectangles;
    vector<Circle> circles;

    rectangles.push_back(Rectangle(5.0, 3.0));
    circles.push_back(Circle(4.0));

    for (const auto& rect : rectangles) {
        cout << "Rectangle area is: " << rect.Area() << endl;
    }

    for (const auto& circ : circles) {
        cout << "Circle area is: " << circ.Area() << endl;
    }

    return 0;
}