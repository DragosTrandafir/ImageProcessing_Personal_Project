#include"Drawing_module.h"
#include <iostream>


void drawCircle(Image& img, Point center, int radius, unsigned char color) {
    for (int x = center.get_x() - radius; x <= center.get_x() + radius; x++) 
        for (int y = center.get_y() - radius; y <= center.get_y() + radius; y++) 
            // Check if the current pixel is inside the circle
            if ((x - center.get_x()) * (x - center.get_x()) + (y - center.get_y()) * (y - center.get_y()) <= radius * radius) 
                img.at(x, y) = color;
            
}
void drawLine(Image& img, Point p1, Point p2, unsigned char color) {
    int aux;
    if (p1.get_x() > p2.get_x()) {
        aux = p1.get_x();
        p1.set_x(p2.get_x());
        p2.set_x(aux);
    }
    if (p1.get_y() > p2.get_y()) {
        aux = p1.get_y();
        p1.set_y(p2.get_y());
        p2.set_y(aux);
    }
    for (int x = p1.get_x(); x <= p2.get_x(); x++)
        for (int y = p1.get_y(); y <= p2.get_y(); y++)
            if ((x * p1.get_y() + p2.get_x() + p1.get_x() + p2.get_y() - p1.get_y() * p2.get_x() - p1.get_x() * y - x * p2.get_y()) == 0)
                img.at(x, y) = color;
}

void drawRectangle(Image& img, Rectangle r, unsigned char color) {
    for (int y = r.get_y(); y <= r.get_y()+r.get_h(); y++)
        for (int x = r.get_x(); x <= r.get_x() + r.get_w(); x++)
            img.at(x, y) = color;
}
void drawRectangle(Image& img, Point tl, Point br, unsigned char color) {
    for (int y = tl.get_y(); y <= br.get_y(); y++) 
        for (int x = tl.get_x(); x <= br.get_x(); x++) 
            img.at(x, y) = color;
}