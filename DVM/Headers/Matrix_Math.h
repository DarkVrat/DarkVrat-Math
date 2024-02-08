#ifndef DVM_MATRIX_MATH_H
#define DVM_MATRIX_MATH_H

#include "Math.h"
#include "Matrix.h"

namespace DVM
{
	template<typename T, size_t N, size_t M>
	inline T Determinant(const MatTemplate<T, N, M>& mat)
	{
		
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, M, N> Inverse(const MatTemplate<T, N, M>& mat)
	{

	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M> MatrixCompMult(const MatTemplate<T, N, M>& matX, const MatTemplate<T, N, M>& matY)
	{

	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M> OuterProduct(const MatTemplate<T, N, M>& matC, const MatTemplate<T, N, M>& matR)
	{

	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, M, N> Transpose(const MatTemplate<T, N, M>& matX)
	{

	}
}

#endif // !DVM_MATRIX_MATH_H

