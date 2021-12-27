//============================================================================
// Name        : image_segmentation.cpp
// Author      : Kushal Gandhi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "include/read_image.h"
#include "include/bitmap.h"

using namespace std;

int main() {
	bitmap_image* bmp = new bitmap_image();
	bmp->read_bitmap_image("/home/kgandhi/Desktop/eclipse-workspace/image_segmentation_cv/src/test_images/test_1.bmp");
	return 0;
}
