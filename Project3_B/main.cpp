#include <iostream>  // only used in doug_test so far

#include "CodeConvert.h"

void doug_test(){
    CodeConvert a;
    a.load_from_file();
	std::cout << a.decode("..._ ..._");
	std::cout << a.decode(".......");
}

int main(){

	doug_test();

	system("pause");
	return 0;
}
