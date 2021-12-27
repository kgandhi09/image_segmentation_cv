/*
 * bitmap.cpp
 *
 *  Created on: Dec 27, 2021
 *      Author: kgandhi
 */

#include "include/bitmap.h"

//default constructor for Color
Color::Color() : r(0), g(0), b(0){}

Color::Color(float r, float g, float b){
	Color::r = r;
	Color::g = g;
	Color::b = b;
}

//de-constructor for color
Color::~Color(){}

//default constructor for bitmap_image
bitmap_image::bitmap_image(): m_width(0), m_height(0){}

bitmap_image::bitmap_image(int width, int height){
	bitmap_image::m_width = width;
	bitmap_image::m_height = height;
	bitmap_image::m_colors = vector<Color>(width*height);
}

//de-constructor for bitmap_image
bitmap_image::~bitmap_image(){}

void bitmap_image::create_bitmap_image(){

}

void bitmap_image::read_bitmap_image(string read_path){

}

void bitmap_image::write_bitmap_image(string write_path){

}

Color bitmap_image::getColor(int x, int y){

}

