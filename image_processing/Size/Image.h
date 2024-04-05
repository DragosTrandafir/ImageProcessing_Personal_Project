#include<iostream>
#include"Rectangle.h"
#include"Size.h"
using namespace std;
#pragma once
class Image
{
public:
	Image(); // default constructor
	Image(unsigned int w, unsigned int h);// param constructor
	Image(const Image& other); // copy constructor
	Image& operator=(const Image& other); // assignment constructr
	~Image(); // destructor

	bool load(std::string imagePath);
	bool save(std::string imagePath) const;
	Image operator+(const Image& img);
	Image operator-(const Image& img);
	Image operator*(double s);
	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	bool isEmpty() const;
	Size size() const;

	unsigned int width() const;
	unsigned int height() const;
	unsigned char** data() const;

	void set_width(unsigned int w);
	void set_height(unsigned int h);
	void set_data(unsigned int val);
	void set_data_2D(unsigned char** data);

	unsigned char& at(unsigned int x, unsigned int y) const;
	unsigned char& at(Point pt) const;
	unsigned char* row(int y);
	void release();
	friend std::ostream& operator<<(std::ostream& os, const Image& dt);
	friend std::istream& operator>>(std::istream& is, Image& dt);
	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);
private:
	unsigned char** m_data;
	unsigned int m_width;
	unsigned int m_height;
};

