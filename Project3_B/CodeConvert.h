#ifndef CODECONVERT_H_
#define CODECONVERT_H_

#include <map>
#include <string>

#include "Binary_Tree.h"

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

    /** read the text file with the code
        and make a map with code keys and character values */
    std::map<std::string, char> load_from_file();
public:

};

#endif
