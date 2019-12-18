#include "Circle.h"
#include "task1.h"

double land_and_rope(){
    Circle Earth(6378.1);
    Circle Rope(0);
    Rope.setFerence(Earth.getFerence()+1);
    return double(Rope.getRadius() - Earth.getRadius());
}

double swimming_pool(){
    Circle Pool(3);
    Circle Road(Pool.getRadius()+1);
    return double(1000*(Road.getArea() - Pool.getArea()) + 2000*Road.getFerence());
    
}
