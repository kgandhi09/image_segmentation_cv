/*
 * bitmap.h
 *
 *  Created on: Dec 27, 2021
 *      Author: kgandhi
 */

#ifndef INCLUDE_BITMAP_H_
#define INCLUDE_BITMAP_H_

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;

struct Color{
	float r;
	float g;
	float b;

	Color();
	Color(float r, float g, float b);
	~Color();

};

class bitmap_image{

private:
	int m_width;
	int m_height;
	vector<Color> m_colors;

public:

	bitmap_image();
	bitmap_image(int image, int height);
	void create_bitmap_image();
	void read_bitmap_image(string read_path);
	void write_bitmap_image(string wrtie_path);
	~bitmap_image();

	Color getColor(int x, int y);
	void setColor(Color& color, int x, int y);

};




#endif /* INCLUDE_BITMAP_H_ */
