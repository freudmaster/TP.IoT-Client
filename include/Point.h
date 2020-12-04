//
// Created by MAGUENDJI Freud on 12/2/20.
//

#ifndef UNTITLED4_POINT_H
#define UNTITLED4_POINT_H
#include <WString.h>
#include "Object.h"

class Point : Object {

private:
    float _x, _y;
    String color;
public:
    Point(const float x, const float y);
    Point();
    const char* toJson() override;

    float getX() const;

    void setX(float x);

    float getY() const;

    const String &getColor() const;

    void setColor(const String &color);

    void setY(float y);


};


#endif //UNTITLED4_POINT_H
