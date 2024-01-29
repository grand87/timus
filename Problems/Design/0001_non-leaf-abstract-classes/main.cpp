#include <iostream>

using namespace std;

class Shape {
    int color;

protected:
    Shape& operator=(const Shape& aShape);

public:
    Shape() : color{ 0 } {

    }

    int getColor() const {
        return color;
    }

    void setColor(int aColor) {
        color = aColor;
    }

    virtual ~Shape() = 0;
};

class Rect : public Shape {

public:
    Rect& operator=(const Rect& aRect) {
        Shape::operator=(aRect);
        //cusotm fields assignment

        return *this;
    }
};

class Circle : public Shape {

public:
    Circle& operator=(const Circle& aRect) {
        Circle::operator=(aRect);
        //cusotm fields assignment

        return *this;
    }
};

void main() {
    Rect r1; r1.setColor(100);
    Rect r2;
    Circle c1;
    Circle c2;

    Shape *s1 = &r1;
    Shape *s2 = &c1;
    Shape *s3 = &r2;
    Shape *s4 = &c2;

    // should work
    r1 = r2;
    c1 = c2;

    // heterogenious assignment should not work
    *s2 = *s1; // should not work
    *s3 = *s1; // should not work

    cout << "c1.getColor() = " << c1.getColor() << endl;
}