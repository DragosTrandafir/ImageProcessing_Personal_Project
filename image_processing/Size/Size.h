#include<iostream>
using namespace std;
#pragma once
class Size
{
public:
	Size();
	Size(unsigned int pwidth, unsigned int pheight);
	//~Size();

	unsigned int get_width() const;
	unsigned int get_height() const;
	unsigned int get_area() const;

	void set_width(unsigned int width);
	void set_height(unsigned int height);


	friend bool operator==(const Size& s1, const Size& s2);
	friend bool operator<(const Size& s1, const Size& s2);
	friend bool operator<=(const Size& s1, const Size& s2);
	friend bool operator>(const Size& s1, const Size& s2);
	friend bool operator>=(const Size& s1, const Size& s2);
private:
	unsigned int height;
	unsigned int width;
};

