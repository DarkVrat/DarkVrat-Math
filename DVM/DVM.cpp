#include <iostream>

#include "Headers/Vector.h"

template<typename T, size_t N>
void printVec(const DVM::VecTemplate<T, N>& vec)
{
	for (size_t i = 0; i < vec.Size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main()
{
	DVM::Vec3i vec3i(14, 345, 56);
	DVM::VecTemplate<float, 4> vec4f(vec3i, 45.f);
	printVec(vec4f);
	printVec(vec3i);
	
}