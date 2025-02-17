#include "Rectangle.h"
#include "Point.h"
#include<iostream>
#include<algorithm>


Rectangle::Rectangle() {
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}
Rectangle::Rectangle(int px, int py, unsigned int pw, unsigned int ph) : x{ px }, y{ py }, w{ pw }, h{ ph } {

}

int Rectangle::get_x() const {
	return x;
}
int Rectangle::get_y() const {
	return y;
}
unsigned int Rectangle::get_w() const {
	return w;
}
unsigned int Rectangle::get_h() const {
	return h;
}

void Rectangle::set_x(int x) {
	this->x = x;
}
void Rectangle::set_y(int y) {
	this->y = y;
}
void Rectangle::set_w(unsigned int w) {
	this->w = w;
}
void Rectangle::set_h(unsigned int h) {
	this->h = h;
}

Rectangle& Rectangle::operator+(const Point& p) {
	this->x += p.get_x(); // the operator which SET or CHANGE attributes should be defined as member functions
	this->y += p.get_y();
	return *this;
}
//intersection operator
Rectangle operator&(const Rectangle& r1, const Rectangle& r2) {
   
    int x1 = r1.get_x() + r1.get_w(); // x-coordinate of the bottom-right vertex of the first rectangle
    int y1 = r1.get_y() + r1.get_h(); // y-coordinate of the bottom-right vertex of the first rectangle
    int x2 = r2.get_x() + r2.get_w(); // x-coordinate of the bottom-right vertex of the second rectangle
    int y2 = r2.get_y() + r2.get_h(); // y-coordinate of the bottom-right vertex of the second rectangle

    // Compute the coordinates of the top-left vertex of the intersection rectangle
    int x_top_left = max(r1.get_x(), r2.get_x());
    int y_top_left = max(r1.get_y(), r2.get_y());

    // Compute the coordinates of the bottom-right vertex of the intersection rectangle
    int x_bottom_right = min(x1, x2);
    int y_bottom_right = min(y1, y2);

    // Check if the rectangles intersect
    if (x_top_left < x_bottom_right && y_top_left < y_bottom_right) {
        // Compute the width and height of the intersection rectangle
        int intersect_width = x_bottom_right - x_top_left;
        int intersect_height = y_bottom_right - y_top_left;

        // Return the intersection rectangle
        return Rectangle(x_top_left, y_top_left, intersect_width, intersect_height);
    }

    // If no intersection, return an empty rectangle
    return Rectangle();
}

// Union operator
Rectangle operator|(const Rectangle& r1, const Rectangle& r2) {
    // Calculate the coordinates of the top-left and bottom-right vertices of the union rectangle
    int x1 = min(r1.get_x(), r2.get_x());
    int y1 = min(r1.get_y(), r2.get_y());
    int x2 = max(r1.get_x() + r1.get_w(), r2.get_x() + r2.get_w());
    int y2 = max(r1.get_y() + r1.get_h(), r2.get_y() + r2.get_h());

    // Calculate the width and height of the union rectangle
    unsigned int union_width = x2 - x1;
    unsigned int union_height = y2 - y1;

    // Return the union rectangle
    return Rectangle(x1, y1, union_width, union_height);
}

