#include<iostream>
using namespace std;
#include "Point.h"
#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(int px, int py, unsigned int pw, unsigned ph);

	int get_x() const;
	int get_y() const;
	unsigned int get_w() const;
	unsigned int get_h() const;

	void set_x(int x);
	void set_y(int y);
	void set_w(unsigned int w);
	void set_h(unsigned int h);

	Rectangle& operator+(const Point& p); // member function
	friend Rectangle operator&(const Rectangle& r1, const Rectangle& r2);
	friend Rectangle operator|(const Rectangle& r1, const Rectangle& r2);
private:
	int x;
	int y;
	unsigned int w;
	unsigned int h;
};

