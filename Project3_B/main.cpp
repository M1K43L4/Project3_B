#include <iostream>

#include "CodeConvert.h"

void test(){
    CodeConvert a;
    a.load_from_file();

	std::cout << std::endl << std::endl;

	std::cout << a.decode("..._ ..._") << std::endl;
	std::cout << a.decode(".......") << std::endl;
	std::cout << a.encode("vv") << std::endl;
	std::cout << a.encode("v v") << std::endl;
	std::cout << a.encode("?") << std::endl;
}

int main(){

	test();

	system("pause");
	return 0;
}
