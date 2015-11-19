#include "CodeConvert.h"
#include <fstream>
#include <iostream>

std::map<std::string, char> CodeConvert::load_from_file(){

	std::map<std::string, char> map_to_return;
	std::ifstream fin("morse.txt");

	if (! (fin.good() && fin.is_open())) {  //if fin didn't open
		// 'morse.txt' file not found.

		//return a junk map to appease the return value of the function
		//std::string junk;
		//char j = 'j';
		//Map[junk] = j;
		return map_to_return;
	}

	std::string key;  // code of dots and dashes
	char value;       // character represented by code

	while (fin >> value >> key){
		map_to_return[key] = value;
	}

	fin.close();

	return map_to_return;
}
