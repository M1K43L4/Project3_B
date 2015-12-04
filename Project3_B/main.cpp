#include <iostream>

#include "CodeConvert.h"

void test(){
    CodeConvert a;
    a.load_from_file();

	std::cout << "/ntesting decode:\n";

	std::cout << a.decode("..._ ..._") << std::endl;
	std::cout << a.decode("_.. ___ .._ __.") << std::endl;
	std::cout << a.decode("__ .. _._ ._ . ._.. ._") << std::endl;
	std::cout << a.decode(".___ . ... ... .. _._. ._") << std::endl;

	std::cout << "\ntesting decode error:\n";

	std::cout << a.decode(".......");

	std::cout << "\ntesting encode:\n";

	std::cout << a.encode("hoskisson") << std::endl;
	std::cout << a.encode("cubon") << std::endl;
	std::cout << a.encode("sevillapulido") << std::endl;
	std::cout << a.encode("vv") << std::endl;

	std::cout << "\ntesting encode error:\n";

	std::cout << a.encode("v v");
	std::cout << a.encode("?");
}

int main(){

	test();

	system("pause");
	return 0;
}
