#include <iostream>

#include "Headers/Matrix.h"
#include "Headers/Matrix_Math.h"
#include <map>
#include <cmath>

template<typename T, size_t C, size_t R>
void printMat(const DVM::MatTemplate<T, C, R>& mat)
{
	for (size_t x = 0; x < C; ++x)
	{
		for (size_t y = 0; y < R; ++y)
			std::cout << mat[x][y] << " ";

		std::cout << std::endl;
	}
}

int main()
{
	DVM::MatTemplate<float, 5, 5> matX = {	 1,  4,  2,  3,  4, 
											 6,  8,  1, -5, -3, 
											 1, -4,  2, -6,  4, 
											-5,  3,  0,  1, -5, 
											 2, -6,  3,  9, -6 };
	

	printMat(matX);
	std::cout << DVM::Determinant(matX);
}