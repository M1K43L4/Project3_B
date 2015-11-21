#ifndef CODECONVERT_H_
#define CODECONVERT_H_

#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#include "Binary_Tree.h"

struct CharData{
    /** for the creation of the binary tree,
        the number of dots in the character's code is needed
        this is used in function create_vector */
    char character;
    int dot_count;
};

class CodeConvert{

	/*
		This class should be able to convert morse code into alphabetized letters (decode) and
		should be able to convert alphabetized letters into morse code (endcode)
	*/

	/* For the morse code---
		Each letter consists of a series of dots and dashes:
		- The dots are represented as periods			.
		- The dashes are represented as underscores		_
	*/
private:
    static const char DOT;  // char used for dot

    Binary_Tree<char> decode_tree;                     // tree used for decoding
    std::unordered_map<char, std::string> encode_map;  // map used for encoding

    /** read the text file with the code
        and fill the map with code keys and character values
        precondition: map_for_tree_creation should be empty
        returns false if file could not be read, true if it is read */
    bool load_map_from_file(std::map<std::string, CharData>& map_for_tree_creation);

    /** fill the vector used to create the code tree
        precondition: vector_for_tree_creation should be empty */
    void create_vector(std::vector<char>& vector_for_tree_creation, const std::map<std::string, CharData>& map_for_tree_creation);

public:
    void load_from_file();

};

#endif
