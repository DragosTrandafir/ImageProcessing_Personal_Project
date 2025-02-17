#include "ImageProcessing.h"
#include<iostream>
#include<cmath>
//brightness and contrast
Br_Ctr::Br_Ctr() {
    this->a = 1;
    this->b = 0;
}
Br_Ctr::Br_Ctr(float pa, float pb) : a{ pa }, b{ pb } {

}

void Br_Ctr::process(const Image& src, Image& dst) {
    for (unsigned int i = 0; i < src.height(); i++)
        for (unsigned int j = 0; j < src.width(); j++)
            if (a * src.at(i, j) + b < 0)
                dst.at(i, j) = 0;
            else if(a * src.at(i, j) + b > 255)
                dst.at(i, j) = 255;
            else
                dst.at(i, j) = (a * src.at(i, j) + b);
}

//gamma correction
Gamma::Gamma() {
    this->y = 1;
}

Gamma::Gamma(float py) : y{ py } {

}

void Gamma::process(const Image& src, Image& dst) {
    for (unsigned int i = 0; i < src.height(); i++)
        for (unsigned int j = 0; j < src.width(); j++)
            if (std::pow(src.at(i, j), y) < 0)
                dst.at(i, j) = 0;
            else if(std::pow(src.at(i, j), y) >255)
                dst.at(i, j) = 255;
            else
                dst.at(i, j) = (std::pow(src.at(i, j), y));
}

//image convolution
Convolution::Convolution() {
    this->w = 0;
    this->h = 0;
    this->kernel = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
    };
}
Convolution::~Convolution() {
    this->kernel = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
    };
    this->w = 0;
    this->h = 0;
}


Convolution::Convolution(std::vector<std::vector<int>> pkernel, unsigned int pw, unsigned int ph) :w{ pw }, h{ ph } {
    this->kernel = pkernel;
}

unsigned int Convolution::width() const {
    return this->w;
}
unsigned int Convolution::height() const {
    return this->h;
}



void Convolution::process(const Image& src, Image& dst) {
    int k1 = kernel.size() / 2; //number of kernl rows
    int k2 = kernel[0].size() / 2; //numbr of kernel columns

    for (unsigned int x = 0; x < src.height(); x++) {
        for (unsigned int y = 0; y < src.width(); y++)
        {
            int sumPixel = 0;
            for (int u = 0; u < kernel.size(); u++) {
                for (int v = 0; v < kernel[0].size(); v++)
                {
                    int imgX = x + u - k1;
                    int imgY = y + v - k2;
                    if (imgX >= 0 && imgX < src.height() && imgY >= 0 && imgY < src.width())//check for negative indexes or out of bounds indexes
                        sumPixel += kernel[u][v] * src.at(imgX, imgY);
                    
                }
            }
                dst.at(x, y) = sumPixel;
        }}
    
}
