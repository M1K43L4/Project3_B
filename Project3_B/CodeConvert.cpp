#include "CodeConvert.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>  // std::count

bool CodeConvert::load_map_from_file(std::map<std::string, CharData>& map_of_codes){

	std::ifstream fin("morse.txt");

	if (! (fin.good() && fin.is_open())) {  //if fin didn't open
		// 'morse.txt' file not found.

		// TODO: error message or something?
		return false;
	}

	std::string key;  // code of dots and dashes
	CharData value;   // struct used as value in map


	while (fin >> value.character >> key){
        value.dot_count = std::count(key.begin(), key.end(), '.');
		map_of_codes[key] = value;
	}

	fin.close();

	return true;
}

void CodeConvert::create_vector(std::vector<char>& vector_for_tree_creation, const std::map<std::string, CharData>& map_of_codes){
    int previous_code_dot_count = 0;
    int dots_removed_plus_one;

    vector_for_tree_creation.push_back(' ');  // root of tree, has no character (this could be any char)

    for (auto itr = map_of_codes.begin(); itr != map_of_codes.end(); ++itr){
        // add to the vector, nulls, numbering (the number of dots removed from the previous code) + 1
        dots_removed_plus_one = previous_code_dot_count + 1 - (itr->second).dot_count;
        // TODO: error if this number is less than zero? (added more than one dot)
        for (; dots_removed_plus_one > 0; --dots_removed_plus_one){
            vector_for_tree_creation.push_back(0);
        }

        // after adding the appropriate number of nulls, add char to vector
        vector_for_tree_creation.push_back((itr->second).character);

        previous_code_dot_count = (itr->second).dot_count;
    }
}

void CodeConvert::load_from_file(){
    std::map<std::string, CharData> map_of_codes;
    std::vector<char> vector_for_tree_creation;

    load_map_from_file(map_of_codes);

    create_vector(vector_for_tree_creation, map_of_codes);

    // test
    // does it put it in the right order like we thought it would?
    for (auto itr = vector_for_tree_creation.begin(); itr != vector_for_tree_creation.end(); ++itr)
        std::cout << *itr << std::endl;

    // TODO: put data in binary tree
}
