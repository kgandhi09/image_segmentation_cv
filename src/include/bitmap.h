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

public:

	bitmap_image();
	void create_bitmap_image(string wrtie_path);
	void read_bitmap_image(string file_path);

};




#endif /* INCLUDE_BITMAP_H_ */
