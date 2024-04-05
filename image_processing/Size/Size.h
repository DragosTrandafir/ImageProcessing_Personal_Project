#include<iostream>
using namespace std;
#pragma once
class Size
{
public:
	Size();
	Size(unsigned int pw, unsigned int ph);
	//~Size();

	unsigned int get_width() const;
	unsigned int get_height() const;
	unsigned int get_area() const;

	void set_width(unsigned int w);
	void set_height(unsigned int h);


	friend bool operator==(const Size& s1, const Size& s2);
	friend bool operator<(const Size& s1, const Size& s2);
	friend bool operator<=(const Size& s1, const Size& s2);
	friend bool operator>(const Size& s1, const Size& s2);
	friend bool operator>=(const Size& s1, const Size& s2);
private:
	unsigned int h;
	unsigned int w;
};

