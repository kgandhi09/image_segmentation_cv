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
	//file type
	fileHeader[0] = 'B';
	fileHeader[1] = 'M';
	//file size
	fileHeader[2] = fileSize;
	fileHeader[3] = fileSize >> 8;
	fileHeader[4] = fileSize >> 16;
	fileHeader[5] = fileSize >> 24;
	//reserved 1 (not used)
	fileHeader[6] = 0;
	fileHeader[7] = 0;
	//reserved 2 (not used)
	fileHeader[8] = 0;
	fileHeader[9] = 0;
	//pixel data offset
	fileHeader[10] = fileHeaderSize + infoHeaderSize;
	fileHeader[11] = 0;
	fileHeader[12] = 0;
	fileHeader[13] = 0;

	char infoHeader[infoHeaderSize];
	//Header Size
	infoHeader[0] = infoHeaderSize;
	infoHeader[1] = 0;
	infoHeader[2] = 0;
	infoHeader[3] = 0;
	//Image Width;
	infoHeader[4] = bitmap_image::m_width;
	infoHeader[5] = bitmap_image::m_width >> 8;
	infoHeader[6] = bitmap_image::m_width >> 16;
	infoHeader[7] = bitmap_image::m_width >> 24;
	//Image Height;
	infoHeader[8] = bitmap_image::m_height;
	infoHeader[9] = bitmap_image::m_height >> 8;
	infoHeader[10] = bitmap_image::m_height >> 16;
	infoHeader[11] = bitmap_image::m_height >> 24;
	//planes
	infoHeader[12] = 1;
	infoHeader[13] = 0;
	//Bits Per Pixel (RGB)_
	infoHeader[14] = 24; //(8 bits per channel R,G,B per pixel)
	infoHeader[15] = 0;
	//compression (no compression)
	infoHeader[16] = 0;
	infoHeader[17] = 0;
	infoHeader[18] = 0;
	infoHeader[19] = 0;
	//Image Size (no compression)
	infoHeader[20] = 0;
	infoHeader[21] = 0;
	infoHeader[22] = 0;
	infoHeader[23] = 0;
	//x pixels per meter (not specified)
	infoHeader[24] = 0;
	infoHeader[25] = 0;
	infoHeader[26] = 0;
	infoHeader[27] = 0;
	//y pixels per meter (not specified)
	infoHeader[28] = 0;
	infoHeader[29] = 0;
	infoHeader[30] = 0;
	infoHeader[31] = 0;
	//Total colors (color palette not used)
	infoHeader[32] = 0;
	infoHeader[33] = 0;
	infoHeader[34] = 0;
	infoHeader[35] = 0;
	//Important colors (generally ignored)
	infoHeader[36] = 0;
	infoHeader[37] = 0;
	infoHeader[38] = 0;
	infoHeader[39] = 0;

	f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
	f.write(reinterpret_cast<char*>(infoHeader), infoHeaderSize);

}














