#include <iostream>
#include "determinant.h"

int main()
{
	size_t lines;
	
	std::cout << "enter number of rows" << std::endl;
	std::cin >> lines;

	determinant A(lines);
	std::cin >> A;
	std::cout << A;
	std::cout << A.logic(A,lines);
}

