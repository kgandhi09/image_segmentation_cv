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
	return bitmap_image::m_colors[y*bitmap_image::m_width + x];
}

void bitmap_image::setColor(Color& color, int x, int y){
	bitmap_image::m_colors[y*bitmap_image::m_width+x].r = color.r;
	bitmap_image::m_colors[y*bitmap_image::m_width+x].g = color.g;
	bitmap_image::m_colors[y*bitmap_image::m_width+x].b = color.b;
}

void bitmap_image::write_bitmap_image(string write_path){

	ofstream f;
	f.open(write_path, ios::out | ios::binary);

	if(!f.is_open()){
		cerr << "Could not open the file, please check if the path is correct!" << endl;
		return;
	}

	//Three parts required to write a bitmap image
	//File Header - General information
	//Information header (DIB header) - Detailed information
	//Pixel array - Color data for each pixel

	char bmpPadding[3] = {0,0,0};
	int paddingAmount = (bitmap_image::m_width*4 - bitmap_image::m_width*3) % 3;

	int fileHeaderSize = 14; //file header size will always be 14 bytes for a bitmap image
	int infoHeaderSize = 40; //info header size will always be 40 bytes for a bitmap image
	int fileSize = fileHeaderSize + infoHeaderSize + (bitmap_image::m_width * bitmap_image::m_height * 3) + (paddingAmount * bitmap_image::m_height);

	char fileHeader[fileHeaderSize];
	//File Type

}














