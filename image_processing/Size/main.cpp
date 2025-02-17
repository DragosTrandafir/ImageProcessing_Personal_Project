#include <iostream>
#include "Image.h"
#include "ImageProcessing.h"
#include <vector>
void printMenu() {
    std::cout << "Option 1: Brightness Contrast" << std::endl;
    std::cout << "Option 2: Gamma Correction" << std::endl;
    std::cout << "Option 3: Convolution" << std::endl;
    std::cout << "Option 4: Save & Stop" << std::endl;
    
}
int main() {

    // instance of the Image class and load an image
    Image inputImage;
    std::string inputImagePath = "C:\\Users\\DragosTrandafiri\\source\\repos\\DragosTrandafir\\ImageProcessing_Personal_Project\\image_processing\\Size\\image1_processing.pgm";

    if (!inputImage.load(inputImagePath)) {
        std::cerr << "Failed to load input image!" << std::endl;
        return 1;
    }

    Image outputImage(inputImage.width(), inputImage.height());


    bool stop = false;
    unsigned option;
    while (!stop) {
        printMenu();
        cout << "Read option:"<<endl;
        cin >> option;
        if (option == 1) {
            float a;
            float b;
            cout << "Read a:" << endl;
            cin >> a;
            cout << "Read b:" << endl;
            cin >> b;

            Br_Ctr brightnessContrast;
            brightnessContrast = Br_Ctr(a, b);
            
           
            brightnessContrast.process(inputImage, outputImage);
        }
        else if (option == 2) {
            float y;
            cout << "Read y:" << endl;
            cin >> y;

            Gamma gammaCorrection;
            gammaCorrection = Gamma(y);

            
            gammaCorrection.process(inputImage, outputImage);
        }
        else if (option == 3) {
            int rows, cols;
            std::cout << "Enter kernel dimensions (rows, cols): ";
            std::cin >> rows >> cols;

            std::vector<std::vector<int>> kernel(rows, std::vector<int>(cols)); //alocate matrix

            std::cout << "Enter kernel values:\n";
            for (int i = 0; i < rows; i++) 
                for (int j = 0; j < cols; j++) 
                    std::cin >> kernel[i][j];

             unsigned int w = 49;
             unsigned int h = 39;


            Convolution convolution;
            convolution = Convolution(kernel, w, h);

            
            convolution.process(inputImage, outputImage);

        }
        else if (option==4)
        {
            std::string outputPath = "C:\\Users\\DragosTrandafiri\\source\\repos\\DragosTrandafir\\ImageProcessing_Personal_Project\\image_processing\\Size\\output_image.pgm";
            if (!outputImage.save(outputPath)) {
                std::cerr << "Failed to save output image!" << std::endl;
                return 1;
            }


            std::cout << "Operation applied successfully!" << std::endl;

            stop = true;
        }
        else
            std::cout << "Option does not exist!" << std::endl;
    }






    return 0;
}
