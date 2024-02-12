#ifndef DVM_MATRIX_MATH_H
#define DVM_MATRIX_MATH_H

#include "Math.h"
#include "Matrix.h"
#include "Vector.h"

namespace DVM
{

	template<typename T> inline T Determinant(const MatTemplate<T, 1, 1>& mat) { return mat[0][0]; }
	template<typename T> inline T Determinant(const MatTemplate<T, 2, 2>& mat) { return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]; }
	template<typename T, size_t C, size_t R>
	constexpr T Determinant(const MatTemplate<T, C, R>& mat)
	{
		static_assert(C == R, "the matrix must be square");
		
		T result = 0;
		T sign = 1;
		MatTemplate<T, C - 1, R - 1> subMat;

		for (size_t i = 0; i < C; ++i)
		{
			for (size_t x = 0; x < C - 1; ++x)
				for (size_t y = 0; y < R - 1; ++y)
						subMat[x][y] = mat[x < i ? x : x + 1][y + 1];

			result += sign * mat[i][0] * Determinant(subMat);
			sign *= -1;
		}

		return result;
	}

	template<typename T, size_t C, size_t R>
	constexpr MatTemplate<T, R, C> Inverse(const MatTemplate<T, C, R>& mat)
	{
		static_assert(C == R, "the matrix must be square");

		T deter = Determinant(mat);
		if (deter == template_cast<T>(0)) return MatTemplate<T, R, C>();

		T sign = 1;
		MatTemplate<T, R, C> resultMat;
		MatTemplate<T, C - 1, R - 1> subMat;

		for (size_t i = 0; i < C; ++i)
			for(size_t j = 0; j < R; ++j)
			{
				for (size_t x = 0; x < C - 1; ++x)
					for (size_t y = 0; y < R - 1; ++y)
						subMat[x][y] = mat[x < i ? x : x + 1][y < j ? y : y + 1];

				resultMat[j][i] = sign * Determinant(subMat);
				sign *= -1;
			}

		resultMat *= 1 / deter;
		return resultMat;
	}

	template<typename T, size_t M, size_t N, size_t K>
	constexpr MatTemplate<T, M, K> matrixMultiplication(const MatTemplate<T, M, N>& matX, const MatTemplate<T, N, K>& matY)
	{
		MatTemplate<T, M, K> result;

		for (size_t i = 0; i < M; ++i) 
			for (size_t j = 0; j < K; ++j) {
				T sum = 0;

				for (size_t k = 0; k < N; ++k)
					sum += matX[i][k] * matY[k][j];
		
				result[i][j] = sum;
			}

		return result;
	}

	template<typename T, size_t C, size_t R>
	constexpr MatTemplate<T, C, R> MatrixCompMult(const MatTemplate<T, C, R>& matX, const MatTemplate<T, C, R>& matY)
	{
		MatTemplate<T, C, R> result;

		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				result.data[i][j] = matX.data[i][j] * matY.data[i][j];

		return result;
	}

	template<typename T, size_t C, size_t R>
	constexpr MatTemplate<T, C, R> OuterProduct(const VecTemplate<T, C>& vecC, const VecTemplate<T, R>& vecR)
	{
		MatTemplate<T, C, R> result;

		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				result.data[i][j] = vecC[i] * vecR[j];

		return result;
	}

	template<typename T, size_t C, size_t R>
	constexpr MatTemplate<T, R, C> Transpose(const MatTemplate<T, C, R>& matX)
	{
		MatTemplate<T, R, C> result;

		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				result.data[j][i] = matX.data[i][j];

		return result;


	}
}

#endif // !DVM_MATRIX_MATH_H

