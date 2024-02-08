#ifndef DVM_MATRIX_H
#define DVM_MATRIX_H

namespace DVM 
{
	template<typename T, size_t N, size_t M>
	struct MatTemplate
	{
		static_assert(N != 0 && M != 0, "N and M must not be zero");

		T data[N][M];

		MatTemplate()
		{
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < M; ++j)
					data[i][j] = T{};
		}

		MatTemplate(T initValues[N * M])
		{
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < M; ++j)
					data[i][j] = initValues[i * M + j];
		}

		MatTemplate(T initValues[N][M])
		{
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < M; ++j)
					data[i][j] = initValues[i][j];
		}

		template<typename... Args>
		MatTemplate(Args... args)
		{
			static_assert(sizeof...(Args) == N * M, "Number of arguments must match matrix size");

			T initValues[] = { args... };

			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < M; ++j)
					data[i][j] = initValues[i * M + j];

		}

		MatTemplate(const MatTemplate& right)
		{
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < M; ++j)
					data[i][j] = right[i][j];
		}

		template<typename U>
		MatTemplate(const MatTemplate<U, N, M>& right)
		{
			for (size_t i = 0; i < N; ++i)
				for (size_t j = 0; j < M; ++j)
					data[i][j] = static_cast<T>(right[i][j]);
		}

		MatTemplate& operator=(const MatTemplate& right)
		{
			if (this != &right)
				for (size_t i = 0; i < N; ++i)
					for (size_t j = 0; j < M; ++j)
						data[i][j] = right[i][j];

			return *this;
		}

		template<typename U>
		MatTemplate& operator=(const MatTemplate<U, N, M>& right)
		{
			if (this != &right)
				for (size_t i = 0; i < N; ++i)
					for (size_t j = 0; j < M; ++j)
						data[i][j] = static_cast<T>(right[i][j]);

			return *this;
		}

		~MatTemplate() {};

		constexpr size_t Size() const { return N*M; }

		inline			T& operator[](size_t index) { return data[index]; }
		inline const	T& operator[](size_t index) const { return data[index]; }

		MatTemplate& operator++();
		MatTemplate& operator--();
		const MatTemplate operator++(int);
		const MatTemplate operator--(int);

		//Composite statements of the VecTemplate class
		MatTemplate& operator*=(T value);
		MatTemplate& operator*=(const MatTemplate& value);
		MatTemplate& operator/=(T value);
		MatTemplate& operator/=(const MatTemplate& value);
		MatTemplate& operator+=(T value);
		MatTemplate& operator+=(const MatTemplate& value);
		MatTemplate& operator-=(T value);
		MatTemplate& operator-=(const MatTemplate& value);
	};

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator++()
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				++data[i][j];

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator--()
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				--data[i][j];

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline const MatTemplate<T, N, M> MatTemplate<T, N, M>::operator++(int)
	{
		MatTemplate temp(*this);
		++(*this);
		return temp;
	}

	template<typename T, size_t N, size_t M>
	inline const MatTemplate<T, N, M> MatTemplate<T, N, M>::operator--(int)
	{
		MatTemplate temp(*this);
		--(*this);
		return temp;
	}

	//Composite statements of the VecTemplate class
	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator*=(T value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] *= value;

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator*=(const MatTemplate& value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] *= value[i][j];

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator/=(T value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] /= value;

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator/=(const MatTemplate& value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] /= value;

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator+=(T value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] += value;

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator+=(const MatTemplate& value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)

				data[i][j] += value[i][j];

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator-=(T value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] -= value;

		return *this;
	}

	template<typename T, size_t N, size_t M>
	inline MatTemplate<T, N, M>& MatTemplate<T, N, M>::operator-=(const MatTemplate& value)
	{
		for (size_t i = 0; i < N; ++i)
			for (size_t j = 0; j < M; ++j)
				data[i][j] -= value[i][j];

		return *this;
	}

	//External operators of the VecTemplate class
	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator*(MatTemplate<T, N, M> lhs, T rhs) 
	{
		lhs *= rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator*(T lhs, MatTemplate<T, N, M> rhs) 
	{
		rhs *= lhs;
		return rhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator*(MatTemplate<T, N, M> lhs, const MatTemplate<T, N, M>& rhs) 
	{
		lhs *= rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator/(MatTemplate<T, N, M> lhs, T rhs) 
	{
		lhs /= rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator/(MatTemplate<T, N, M> lhs, const MatTemplate<T, N, M>& rhs) 
	{
		lhs /= rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator+(MatTemplate<T, N, M> lhs, T rhs) 
	{
		lhs += rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator+(MatTemplate<T, N, M> lhs, const MatTemplate<T, N, M>& rhs) 
	{
		lhs += rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator-(MatTemplate<T, N, M> lhs, T rhs) 
	{
		lhs -= rhs;
		return lhs;
	}

	template<typename T, size_t N, size_t M>
	MatTemplate<T, N, M> operator-(MatTemplate<T, N, M> lhs, const MatTemplate<T, N, M>& rhs) 
	{
		lhs -= rhs;
		return lhs;
	}
}

#endif // !DVM_MATRIX_H
