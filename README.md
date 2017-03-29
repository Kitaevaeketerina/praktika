#pragma once
#define _USE_MATH_DEFINES 
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Circle {
private:
    double Radius, Ference, Area;
public:
    Circle() {
        Radius = 1;
        Ference = 2 * M_PI;
        Area = M_PI;
    }
    Circle(double a) {
        Radius = a;
        Ference = 2 * M_PI*Radius;
        Area = Ference*Radius / 2;
    }
    void SetRadius(double a) {
        Radius = a;
        Ference = 2 * M_PI*Radius;
        Area = Ference*Radius / 2;
    }
    void SetFerence(double a) {
        Ference = a;
        Radius = Ference / (2 * M_PI);
        Area = Ference*Radius / 2;
    }
    void SetArea(double a) {
        Area = a;
        Radius = sqrt(Area / M_PI);
        Ference = 2 * M_PI*Radius;
    }
    double GetRadius() {
        return Radius;
    }
    double GetFerence() {
        return Ference;
    }
    double GetArea() {
        return Area;
    }

};
