//
// Created by MAGUENDJI Freud on 12/2/20.
//

#include "Point.h"
const char* Point::toJson() {
    String str;
    str="";
    str=str+"{";
    str=str+R"("x":")"+getX()+"\",";
    str=str+R"("y":")"+getY()+"\",";
    str=str+R"("color":")"+getColor().c_str()+"\"}";
    auto c=str.c_str();
    return c;
}

Point::Point(const float x, const float y) {
    this->_x=x;
    this->_y=y;
    this->color="";
}

Point::Point():Point(0,0) {}

float Point::getX() const {
    return _x;
}

void Point::setX(float x) {
    _x = x;
}

float Point::getY() const {
    return _y;
}

void Point::setY(float y) {
    _y = y;
}

const String &Point::getColor() const {
    return color;
}

void Point::setColor(const String &color) {
    Point::color = color;
}

