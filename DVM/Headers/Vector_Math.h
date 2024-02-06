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

}

#endif // !DVM_VECTOR_FUNCTIONS_H

