#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(make_unique<Circle>(4.0));

    for (const auto& shape : shapes) {
        if (dynamic_cast<Rectangle*>(shape.get())) {
            cout << "Rectangle area is: " << shape->Area() << endl;
        } else if (dynamic_cast<Circle*>(shape.get())) {
            cout << "Circle area is: " << shape->Area() << endl;
        }
    }

    return 0;
}