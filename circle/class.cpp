#include "class.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

Circle::Circle(double radius)
	{
		set_the_radius(radius);
	}

void Circle::set_the_radius(double radius)
	{
		this->radius = radius;
		this->ference = 2*(M_PI)*radius;
		this->area = M_PI*pow(radius, 2);
		//cout << radius << "," << ference << "," << area << endl;
	}

void Circle::set_the_ference(double ference)
	{
		this->ference = ference;
		this->radius = ference/(2*M_PI);
		this->area = 2*pow(radius, 2);
		//cout << radius << ",   " << ference << ",   " << area << endl;
	}

void Circle::set_the_area(double area)
	{
		this->area = area;
		this->radius = sqrt(area*M_PI);
		this->ference = 2*M_PI*radius;
		//cout << radius << "," << ference << "," << area << endl;
	}

double Circle::get_radius()
	{
		return radius;
	}

double Circle::get_area()
	{
		return area;
	}

double Circle::get_ference()
	{
		return ference;
	}

	Circle::Circle()
	{
		set_the_radius(0);
	}