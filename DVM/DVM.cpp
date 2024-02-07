#include <iostream>

#include "Headers/Vector.h"
#include "Headers/Vector_Math.h"
#include <map>
#include <cmath>

template<typename T, size_t N>
void printVec(const DVM::VecTemplate<T, N>& vec)
{
	for (size_t i = 0; i < vec.Size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main()
{
	DVM::Vec3f vec1(1.f, 2.f, 3.f);
	DVM::Vec3f vec2(3.f, 2.f, 1.f);
	DVM::Vec3f vec3(DVM::Cross(vec1, vec2));
	std::cout << vec3.Values.x << " " << vec3.Values.y << " " << vec3.Values.z;
}