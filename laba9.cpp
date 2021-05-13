#include <iostream>
#include "determinant.h"

int main()
{
	try{
	size_t lines;
	
	std::cout << "enter number of rows" << std::endl;
	std::cin >> lines;

	determinant A(lines);
	std::cin >> A;
	std::cout << A;
	std::cout << A.logic(A,lines);
}
catch (const char* error) {
	std::cout << error << std::endl;
}
return 0;
}

