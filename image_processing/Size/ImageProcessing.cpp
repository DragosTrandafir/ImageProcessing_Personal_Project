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
                dst.at(i, j) = static_cast<unsigned char>(a * src.at(i, j) + b);
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
                dst.at(i, j) = static_cast<unsigned char>(std::pow(src.at(i, j), y));
}

//image convolution
Convolution::Convolution() {
    this->w = 0;
    this->h = 0;
    this->kernel = nullptr;
}
Convolution::~Convolution() {
    if (this->kernel) {
        delete[] this->kernel;
    }
    this->kernel = nullptr;
    this->w = 0;
    this->h = 0;
}


Convolution::Convolution(unsigned int** pkernel, unsigned int pw, unsigned int ph) :w{ pw }, h{ ph } {
    kernel = new unsigned int* [h];
    for (unsigned int i = 0; i < h; ++i) {
        kernel[i] = new unsigned int[w];
    }
    /*
    for (unsigned int i = 0; i < h; ++i) {
        for (unsigned int j = 0; j < w; ++j) {
            kernel[i][j] = pkernel[i][j];
        }
    }*/
}

unsigned int Convolution::width() const {
    return this->w;
}
unsigned int Convolution::height() const {
    return this->h;
}



void Convolution::process(const Image& src, Image& dst) {
    // Ensure the kernel is not null and has a valid size
    if (kernel == nullptr || w == 0 || h == 0 || w % 2 == 0 || h % 2 == 0) {
        std::cerr << "Invalid kernel or kernel size." << std::endl;
        return;
    }

    // calculate the half-width and half-height of the kernel
    int halfWidth = w / 2;
    int halfHeight = h / 2;

    // apply convolution to each pixel in the src image
    for (unsigned int y = 0; y < src.height(); ++y) {
        for (unsigned int x = 0; x < src.width(); ++x) {
            float sum = 0.0f;
            // iterate over the kernel
            for (int ky = -halfHeight; ky <= halfHeight; ++ky) {
                for (int kx = -halfWidth; kx <= halfWidth; ++kx) {
                    // calculate the coordinates in the source image
                    int srcX = x + kx;
                    int srcY = y + ky;
                    // check if the coordinates are within the bounds of the source image
                    if (srcX >= 0 && srcX < static_cast<int>(src.width()) &&
                        srcY >= 0 && srcY < static_cast<int>(src.height())) {
                        // calculate the indices for the kernel matrix
                        int kernelX = kx + halfWidth;
                        int kernelY = ky + halfHeight;
                        // multiply corresponding pixel value with kernel value
                        sum += src.at(srcY, srcX) * kernel[kernelY][kernelX];
                    }
                }
            }
            // valid range [0, 255]
            if (sum < 0)
                dst.at(y, x) = 0;
            else if (sum > 255)
                dst.at(y, x) = 255;
            else
                dst.at(y, x) = static_cast<unsigned char>(sum);
        }
    }
}