#include "task1.h"
#include "Circle.h"

double calcDelta() {
	Circle Earth(6378100.0);
	Earth.setFerence(Earth.getFerence() + 1.0);
	return Earth.getRadius() - 6378100.0;
}
double calcCost() {
	Circle Pool(3);
	Circle PoolPath(4);
	return ((PoolPath.getArea() - Pool.getArea()) * 1000 + PoolPath.getFerence() * 2000);
}