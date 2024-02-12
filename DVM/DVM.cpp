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
	DVM::MatTemplate<int, 3, 2> matX = { 3,4,-2,5,1,2 };
	DVM::MatTemplate<int, 2, 3> matY = { 6,2,4,-1,3,-5 };

	printMat(DVM::matrixMultiplication(matX, matY));
	//std::cout << DVM::Determinant(mat);
}