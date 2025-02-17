#include "Size.h"
#include<iostream>

Size::Size() {
	this->height = 0;
	this->width = 0;
}
Size::Size(unsigned int pwidth, unsigned int pheight) : width{ pwidth }, height{ pheight } {

}

unsigned int Size::get_width() const {
	return this->width;
}
unsigned int Size::get_height() const {
	return height;
}
unsigned int Size::get_area() const {
	return (height * width);
}

void Size::set_width(unsigned int width) {
	this->width = width;
}
void Size::set_height(unsigned int height) {
	this->height = height;
}

bool operator==(const Size& s1, const Size& s2) {
	return (s1.get_area() == s2.get_area());
}
bool operator<(const Size& s1, const Size& s2) {
	return (s1.get_area() < s2.get_area());
}
bool operator<=(const Size& s1, const Size& s2) {
	return (s1.get_area() <= s2.get_area());
}
bool operator>(const Size& s1, const Size& s2) {
	return (s1.get_area() > s2.get_area());
}
bool operator>=(const Size& s1, const Size& s2) {
	return (s1.get_area() >= s2.get_area());
}