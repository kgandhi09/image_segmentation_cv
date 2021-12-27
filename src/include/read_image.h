/*
 * read_image.h
 *
 *  Created on: Dec 23, 2021
 *      Author: kgandhi
 */



#ifndef INCLUDE_READ_IMAGE_H_
#define INCLUDE_READ_IMAGE_H_

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;

class image_reader{
public:

	string file_path;

	image_reader(string file_path);
	void open_file();


};



#endif /* INCLUDE_READ_IMAGE_H_ */
