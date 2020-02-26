#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>

Circle::Circle(double radius) 
{
	Circle::setRadius(radius);
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
	ference = 2 * M_PI * radius;
	area = M_PI * radius * radius;
}
void Circle::setFerence(double ference)
{
	this->ference = ference;
	radius = ference / (2 * M_PI);
	area = M_PI * radius * radius;
}
void Circle::setArea(double area)
{
	this->area = area;
	radius = ference / (2 * M_PI);
	ference = 2 * M_PI * radius;
}
double Circle::getRadius()
{
	return radius;
}
double Circle::getFerence()
{
	return ference;
}
double Circle::getArea()
{
	return area;
}
