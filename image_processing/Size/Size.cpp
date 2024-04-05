#include "Size.h"
#include<iostream>

Size::Size() {
	this->h = 0;
	this->w = 0;
}
Size::Size(unsigned int pw, unsigned int ph) : w{ pw }, h{ ph } {

}

unsigned int Size::get_width() const {
	return w;
}
unsigned int Size::get_height() const {
	return h;
}
unsigned int Size::get_area() const {
	return (h * w);
}

void Size::set_width(unsigned int w) {
	this->w = w;
}
void Size::set_height(unsigned int h) {
	this->h = h;
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