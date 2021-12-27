/*
 * image_reader.cpp
 *
 *  Created on: Dec 23, 2021
 *      Author: kgandhi
 */


#include "include/read_image.h"

image_reader::image_reader(string file_path){
	image_reader::file_path = file_path;
}

void image_reader::open_file(){
	vector<string> data;
	string line_data;
	ifstream image(image_reader::file_path, ios::binary);
	if(!image){
		cerr << "can't open the file! "<< endl;
	}
	while(!image.eof()){
		getline(image, line_data, '\0');
		data.push_back(line_data);
	}

	for(string line_data : data){
		cout << line_data << endl;
	}

}
