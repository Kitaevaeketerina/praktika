#include "class.h"
#include <conio.h>
#include <iostream>

int main() {
    Circle circle1(6378100);
    Circle circle2;
    circle2.SetFerence(circle1.GetFerence() + 1);

    cout << "Radius of the rope - Radius of the Earth = \n" <<
        circle2.GetRadius()<< "-" <<circle1.GetRadius() <<"="<<
        circle2.GetRadius() - circle1.GetRadius() << endl;

    Circle circle3(3);
    Circle circle4(4);
    double dorozhka = (circle4.GetArea() - circle3.GetArea()) * 1000;
    double zabor = circle4.GetFerence() * 2000;
    double vsego = dorozhka + zabor;

    cout << "The price of the walkway around the pool " << dorozhka << endl;
    cout << "Price for fence" << zabor << endl;
    cout << "Price for all: " << vsego << endl;
    _getch();
    return 0;
}