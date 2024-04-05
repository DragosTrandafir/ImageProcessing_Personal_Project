#include "Point.h"
#include<iostream>

Point::Point() {
	this->x = 0;
	this->y = 0;
}
Point::Point(int px, int py) : x{ px }, y{ py } {

}

int Point::get_x() const {
	return x;
}
int Point::get_y() const {
	return y;
}

void Point::set_x(int x) {
	this->x = x;
}
void Point::set_y(int y) {
	this->y = y;
}
