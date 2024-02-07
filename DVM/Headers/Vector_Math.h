#ifndef DVM_VECTOR_FUNCTIONS_H
#define DVM_VECTOR_FUNCTIONS_H

#include "Math.h"
#include "Vector.h"

namespace DVM
{
	template<typename T, size_t N>
	inline VecTemplate<T, N> Abs(const VecTemplate<T, N>& vec)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Abs(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Min(const VecTemplate<T, N>& vec, T val)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Min(vec[i], val);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Min(const VecTemplate<T, N>& vec, const VecTemplate<T, N>& vec2)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Min(vec[i], vec2[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Max(const VecTemplate<T, N>& vec, T val)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Max(vec[i], val);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Max(const VecTemplate<T, N>& vec, const VecTemplate<T, N>& vec2)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Max(vec[i], vec2[i]);
		return result;
	}


	template<typename T, size_t N>
	inline VecTemplate<T, N> Clamp(const VecTemplate<T, N>& vec, T min, T max) 
	{ 
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Clamp(vec[i], min, max);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Clamp(const VecTemplate<T, N>& vec, const VecTemplate<T, N>& min, const VecTemplate<T, N>& max)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Clamp(vec[i], min[i], max[i]);
		return result;
	}

	template<size_t N>
	inline VecTemplate<int, N> FloatBitsToInt(const VecTemplate<float, N>& vec)
	{
		VecTemplate<int, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = FloatBitsToInt(vec[i]);
		return result;
	}

	template<size_t N>
	inline VecTemplate<unsigned int, N> FloatBitsToUint(const VecTemplate<float, N>& vec)
	{
		VecTemplate<unsigned int, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = FloatBitsToUint(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Ceil(const VecTemplate<T, N>& vec)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Ceil(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Floor(const VecTemplate<T, N>& vec)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Floor(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Round(const VecTemplate<T, N>& vec)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Round(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Fract(const VecTemplate<T, N>& vec)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Fract(vec[i]);
		return result;
	}

	template<size_t N>
	inline VecTemplate<float, N> IntBitsToFloat(const VecTemplate<int, N>& vec)
	{
		VecTemplate<float, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = IntBitsToFloat(vec[i]);
		return result;
	}

	template<size_t N>
	inline VecTemplate<float, N> UintBitsToFloat(const VecTemplate<unsigned int, N>& vec)
	{
		VecTemplate<float, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = UintBitsToFloat(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<bool, N> Isinf(const VecTemplate<T, N>& vec)
	{
		VecTemplate<bool, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Isinf(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<bool, N> Isnan(const VecTemplate<T, N>& vec)
	{
		VecTemplate<bool, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Isnan(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Mod(const VecTemplate<T, N>& vec)
	{
		VecTemplate<bool, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Mod(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Sign(const VecTemplate<T, N>& vec)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Sign(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Step(const VecTemplate<T, N>& vec, T x) 
	{ 
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Step(vec[i], x);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Step(const VecTemplate<T, N>& vec, const VecTemplate<T, N>& vec2)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Step(vec[i], vec2[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Exp(const VecTemplate<T, N>& vec) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Exp(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Exp2(const VecTemplate<T, N>& vec) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Exp2(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Inversesqrt(const VecTemplate<T, N>& vec) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Inversesqrt(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Log(const VecTemplate<T, N>& vec) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Log(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Log2(const VecTemplate<T, N>& vec) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Log2(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Pow(const VecTemplate<T, N>& vecbase, T exp)
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Pow(vecbase[i], exp);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Pow(const VecTemplate<T, N>& vecbase, const VecTemplate<T, N>& vecexp) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Pow(vecbase[i], vecexp[i]);
		return result;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Sqrt(const VecTemplate<T, N>& vec) 
	{
		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = Sqrt(vec[i]);
		return result;
	}

	template<typename T, size_t N>
	inline T Length(const VecTemplate<T, N>& vec)
	{
		return vec.length();
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N> Normalize(const VecTemplate<T, N>& vec)
	{
		floatingPoint_t<T> length = vec.length();

		if (length < getEpsilon<T>()) return VecTemplate<T, N>();

		VecTemplate<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = vec[i]/length;

		return result;
	}

	template<typename T, size_t N>
	inline T Distance(const VecTemplate<T, N>& p1, const VecTemplate<T, N>& p2)
	{
		return Length(p1-p2);
	}

	template<typename T>
	inline VecTemplate<T, 3> Cross(const VecTemplate<T, 3>& vec1, const VecTemplate<T, 3>& vec2)
	{
		return VecTemplate<T, 3>(
			vec1.Values.y * vec2.Values.z - vec1.Values.z * vec2.Values.y,
			vec1.Values.z * vec2.Values.x - vec1.Values.x * vec2.Values.z,
			vec1.Values.x * vec2.Values.y - vec1.Values.y * vec2.Values.x
			);
	}
}

#endif // !DVM_VECTOR_FUNCTIONS_H

