#include <iostream>

#include "Headers/Vector.h"
#include <map>

template<typename T, size_t N>
void printVec(const DVM::VecTemplate<T, N>& vec)
{
	for (size_t i = 0; i < vec.Size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main()
{
	DVM::VecTemplate<int, 3> vec1(1, 2, 3);
	DVM::VecTemplate<int, 3> vec2(4, 5, 6);
	DVM::VecTemplate<int, 3> vec3 = vec2 << vec1;
	std::cout << vec3.Values.x << " " << vec3.Values.y << " " << vec3.Values.z;
}