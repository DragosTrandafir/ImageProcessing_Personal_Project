#include <iostream>
#include "Image.h"
#include "ImageProcessing.h"

int main() {
    Image image;

    // instance of the Image class and load an image
    Image inputImage;
    std::string imagePath = "image1_processing.pgm";
    if (!inputImage.load(imagePath)) {
        std::cerr << "Failed to load input image!" << std::endl;
        return 1;
    }

    Br_Ctr brightnessContrast;
    //Gamma gammaCorrection;
    //Convolution convolution;

    float a = 2; 
    float b = 0; 
    brightnessContrast = Br_Ctr(a, b);

    //float y = 1.4;
    //gammaCorrection = Gamma(y);

    
    /*
    unsigned int** pkernel = new unsigned int* [3]; 
    for (int i = 0; i < 3; ++i) {
        pkernel[i] = new unsigned int[3];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            pkernel[i][j] = 1;
    }*/
            
    //convolution = Convolution(pkernel,3, 3);
    

    Image outputImage(inputImage.width(), inputImage.height());

    brightnessContrast.process(inputImage, outputImage);
    //gammaCorrection.process(inputImage, outputImage);
    //convolution.process(inputImage, outputImage);

    std::string outputPath = "output_image.pgm";
    if (!outputImage.save(outputPath)) {
        std::cerr << "Failed to save output image!" << std::endl;
        return 1;
    }

    std::cout << "Operation applied successfully!" << std::endl;

    /*
    for (int i = 0; i < 3; ++i) {
        delete[] pkernel[i];
    }
    delete[] pkernel;
    */
    return 0;
}