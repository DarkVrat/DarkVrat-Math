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
	DVM::Vec3f vec(1, 2, 3);
	DVM::MatTemplate<float, 3, 1> mat=vec;
	printMat(mat);
}