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

    //Br_Ctr brightnessContrast; //1
    //Gamma gammaCorrection; //2
   

    //float a = 2; //1
    //float b = 0;  //1
   // brightnessContrast = Br_Ctr(a, b);  //1

    //float y = 1.4; //2
    //gammaCorrection = Gamma(y); //2

    

    Image outputImage(inputImage.width(), inputImage.height());

    //brightnessContrast.process(inputImage, outputImage);  //1
    //gammaCorrection.process(inputImage, outputImage);//2

    std::string outputPath = "output_image.pgm";
    if (!outputImage.save(outputPath)) {
        std::cerr << "Failed to save output image!" << std::endl;
        return 1;
    }

    std::cout << "Operation applied successfully!" << std::endl;

    return 0;
}
