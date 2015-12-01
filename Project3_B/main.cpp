#include <iostream>  // only used in doug_test so far

#include "CodeConvert.h"

void doug_test(){
    CodeConvert a;
    a.load_from_file();

	std::cout << std::endl << std::endl;

	std::cout << a.decode("..._ ..._");
	std::cout << a.decode(".......");
	std::cout << a.encode("vv");
	std::cout << a.encode("v v");
	std::cout << a.encode("?");
}

int main(){

	doug_test();

	system("pause");
	return 0;
}
