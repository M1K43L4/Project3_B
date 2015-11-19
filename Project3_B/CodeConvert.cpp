#include "CodeConvert.h"
#include <fstream>
#include <iostream>

std::map<std::string, char> CodeConvert::load_from_file(){
	
	std::map<std::string, char> Map;
	std::ifstream fin("morse.txt");

	if (!fin)//if fin didn't open
	{
		// 'morse.txt' file not found.

		//return a junk map to appease the return value of the function
		std::string junk;
		char j = 'j';
		Map[junk] = j;
		return Map;
	}

	std::string key;
	char value;
	while (fin){
		fin >> value;
		fin >> key;

		Map[key] = value;
	}

		
	fin.close();
	return Map;

}