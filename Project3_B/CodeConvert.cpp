#include "CodeConvert.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>  // std::count

const char CodeConvert::DOT = '.';  // char used for dot

bool CodeConvert::load_map_from_file(std::map<std::string, CharData>& map_for_tree_creation){

	std::ifstream fin("morse.txt");

	if (! (fin.good() && fin.is_open())){  // if fin didn't open
		// 'morse.txt' file not found.
		return false;
	}

	std::string code;  // code of dots and dashes
	CharData value;    // struct used as value in map_for_tree_creation


	while (fin >> value.character >> code){
        value.dot_count = std::count(code.begin(), code.end(), DOT);
		map_for_tree_creation[code] = value;
		encode_map[value.character] = code;
	}

	fin.close();

	return true;
}

void CodeConvert::create_vector(std::vector<char>& vector_for_tree_creation,
                                const std::map<std::string, CharData>& map_for_tree_creation){
    int previous_code_dot_count = 0;
    int dots_removed_plus_one;

    vector_for_tree_creation.push_back(' ');  // root of tree, has no character (this could be any char)

    for (auto itr = map_for_tree_creation.begin(); itr != map_for_tree_creation.end(); ++itr){
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
    std::map<std::string, CharData> map_for_tree_creation;
    std::vector<char> vector_for_tree_creation;

    load_map_from_file(map_for_tree_creation);
    // TODO: check for return false for file open error

    create_vector(vector_for_tree_creation, map_for_tree_creation);

    // test, TODO: remove tests?
    // does it put it in the right order like we thought it would?
    for (auto itr = vector_for_tree_creation.begin(); itr != vector_for_tree_creation.end(); ++itr)
        std::cout << *itr << std::endl;

    decode_tree.read_tree(vector_for_tree_creation);

    // test
    std:: cout << decode_tree.to_string();

}
