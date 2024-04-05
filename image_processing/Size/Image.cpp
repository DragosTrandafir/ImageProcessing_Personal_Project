#include "Image.h"
#include<iostream>
#include <fstream>
#include <sstream>

Image::Image() {
	this->m_data = nullptr;
	this->m_width = 0;
	this->m_height = 0;
}
Image::Image(unsigned int w, unsigned int h) : m_width{ w }, m_height{ h } {
    // Allocate memory for the image data array (2D array)
    this->m_data = new unsigned char* [m_height]; // Allocate an array of pointers (for rows)

    for (unsigned int i = 0; i < m_height; i++) {
        // Allocate memory for each row of the image data array (for columns)
        this->m_data[i] = new unsigned char[m_width](); // Initialize all pixels to zero
    }
}

//copy constructor
Image::Image(const Image& other) {
    this->m_width = other.m_width;
    this->m_height = other.m_height;
    m_data = new unsigned char* [m_height];
    for (unsigned int i = 0; i < m_height; i++) {
        m_data[i] = other.m_data[i];
    }
}
//assignment constructor
Image& Image::operator=(const Image& other) {
    if (this != &other) {
        if (m_data)
            delete[] m_data;// free the memory

        //deep copy
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        m_data = new unsigned char* [m_height];
        for (unsigned int i = 0; i < m_height; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}
void Image::release() {
    if (m_data) {
        delete[] m_data;
        m_data = nullptr;
    }
}
//destructor
Image::~Image() {
    release();
}
//setters and getters for width and height
unsigned int Image::width() const {
    return m_width;
}
unsigned int Image::height() const {
    return m_height;
}
unsigned char** Image::data() const {
    return m_data;
}
void Image::set_width(unsigned int w) {
    this->m_width = w;
}
void Image::set_height(unsigned int h) {
    this->m_height = h;
}
void Image::set_data(unsigned int val) {
    if (m_data)
        for (unsigned int i = 0; i < m_height; i++)
            for (unsigned int j = 0; j < m_width; j++)
                this->m_data[i][j] = val;
    else
        exit(-1);
}
void Image::set_data_2D(unsigned char** data) {
    if (m_data && data) {
        for (unsigned int i = 0; i < m_height; i++)
            for (unsigned int j = 0; j < m_width; j++)
                this->m_data[i][j] = data[i][j];
        delete[] data;
    }
    else
        exit(-1);
}
Size Image::size() const {
    return Size(m_width, m_height);
}
bool Image::isEmpty() const {
    if (m_data==nullptr && m_width == 0 && m_width == m_height)
        return true;
    return false;
}

//operators
std::ostream& operator<<(std::ostream& os, const Image& dt) {
    os << "P2" << std::endl;
    os << "# Simple pgm image" << std::endl;
    os << dt.m_width << " " << dt.m_height << std::endl;
    os << 225 << std::endl;
    for (unsigned int i = 0; i < dt.m_height; i++) {
        for (unsigned int j = 0; j < dt.m_width; j++)
            os << dt.m_data[i][j] << " ";
        os << endl;
    }
    return os;
}
std::istream& operator>>(std::istream& is, Image& dt) {
    is >> dt.m_width >> dt.m_height;
    for (unsigned int i = 0; i < dt.m_height; i++) {
        for (unsigned int j = 0; j < dt.m_width; j++)
            is>>dt.m_data[i][j];
    }
    return is;
}
bool Image::load(std::string imagePath) {
    std::ifstream file(imagePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << imagePath << std::endl;
        return false;
    }

    std::string magicNumber;
    std::getline(file, magicNumber); // Read the magic number (P2)

    // Check if the file format is supported
    if (magicNumber != "P2") {
        std::cerr << "Error: Unsupported file format." << std::endl;
        return false;
    }

    std::string comment;
    std::getline(file, comment); // Read and ignore the comment line

    std::string dimensions;
    std::getline(file, dimensions); // Read dimensions (width and height)
    std::stringstream dimStream(dimensions);
    dimStream >> m_width >> m_height;

    int maxPixelValue;
    file >> maxPixelValue; // Read the maximum pixel value

    // Allocate memory for the image data array (2D array)
    m_data = new unsigned char* [m_height];
    for (unsigned int i = 0; i < m_height; i++) {
        m_data[i] = new unsigned char[m_width];
        for (unsigned int j = 0; j < m_width; j++) {
            int pixelValue;
            file >> pixelValue; // Read pixel values
            m_data[i][j] = static_cast<unsigned char>(pixelValue);
        }
    }

    file.close();
    return true;
}

bool Image::save(std::string imagePath) const {
    std::ofstream file(imagePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << imagePath << std::endl;
        return false;
    }

    file << "P2" << std::endl; // Write the magic number
    file << "# Generated by Image class" << std::endl; // Comment line
    file << m_width << " " << m_height << std::endl; // Dimensions

    int maxPixelValue = 255; // Maximum pixel value for PGM format
    file << maxPixelValue << std::endl; // Write the maximum pixel value

    // Write pixel values
    for (unsigned int i = 0; i < m_height; i++) {
        for (unsigned int j = 0; j < m_width; j++) {
            file << static_cast<int>(m_data[i][j]) << " ";
        }
        file << std::endl;
    }

    file.close();
    return true;
}

static Image zeros(unsigned int width, unsigned int height) {
    Image img(width, height);
    img.set_data(0);
    return img;
}

static Image ones(unsigned int width, unsigned int height) {
    Image img(width, height);
    img.set_data(1);
    return img;
}

unsigned char& Image::at(unsigned int x, unsigned int y) const{
    return m_data[x][y];
}
unsigned char& Image::at(Point pt) const{
    return m_data[pt.get_x()][pt.get_y()];
}
unsigned char* Image::row(int y) {
    return m_data[y];
}

Image Image::operator+(const Image& img) {
    if ((this->m_width) != img.m_width || (this->m_height) != img.m_height)
        exit(-1);
    else {
         Image result(m_width, m_height);
         for (unsigned int i = 0; i < m_height; i++) 
             for (unsigned int j = 0; j < m_width; j++) 
                 result.at(i, j) = this->at(i, j) + img.at(i, j);
          return result;
        }

}
Image Image::operator-(const Image& img) {
    if ((this->m_width) != img.m_width || (this->m_height) != img.m_height)
        exit(-1);
    else {
        Image result(m_width, m_height);
        for (unsigned int i = 0; i < m_height; i++)
            for (unsigned int j = 0; j < m_width; j++)
                result.at(i, j) = this->at(i, j) - img.at(i, j);
        return result;
    }
}
Image Image::operator*(double s) {
    for (unsigned int i = 0; i < m_height; i++)
        for (unsigned int j = 0; j < m_width; j++)
            if (m_data[i][j] * s < 0)
                this->m_data[i][j] = 0;
            else if (m_data[i][j] * s > 255)
                this->m_data[i][j] = 255;
            else
                this->m_data[i][j] = static_cast<unsigned char>(m_data[i][j] * s);
    return *this;
}

bool Image::getROI(Image& roiImg, Rectangle roiRect) {
    if (roiRect.get_h() != 0 && roiRect.get_w() != 0) {
        roiImg.set_width(roiRect.get_w());
        roiImg.set_height(roiRect.get_h());
        for (unsigned int i = roiRect.get_x(); i <= (roiRect.get_x() + roiRect.get_h()); i++)
            for (unsigned int j = roiRect.get_y(); j <= (roiRect.get_y() + roiRect.get_w()); j++)
                roiImg.at(i, j) = this->at(i, j);
        return true;
    }
    return false;
}
bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if (height != 0 && width != 0) {
    roiImg.set_width(width);
    roiImg.set_height(height);
    for (unsigned int i = x; i <= (x + height); i++)
        for (unsigned int j = y; j <= (y + width); j++)
            roiImg.at(i, j) = this->at(i, j);
    return true;
}
return false;
}