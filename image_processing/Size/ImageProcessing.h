#include<iostream>
#include"Image.h"
#include <functional>
#include<vector>
using namespace std;
#pragma once
class ImageProcessing
{
public:
	virtual void process(const Image& src, Image& dst)=0;
};

//brightness and contrast
class Br_Ctr : public ImageProcessing{
public:
	Br_Ctr();
	Br_Ctr(float pa, float pb);


	void process(const Image& src, Image& dst) override;
private:
	float a;
	float b;
};

//gamma correction
class Gamma : public ImageProcessing {
public:
	Gamma();
	Gamma(float py);


	void process(const Image& src, Image& dst) override;
private:
	float y;
};


//image convolution
class Convolution : public ImageProcessing {
public:
	Convolution();
	Convolution(std::vector<std::vector<int>> pkernel, unsigned int pw, unsigned int ph);
	~Convolution();
	unsigned int width() const;
	unsigned int height() const;

	void process(const Image& src, Image& dst) override;
private:
	std::vector<std::vector<int>> kernel;
	unsigned int w;
	unsigned int h;
};
