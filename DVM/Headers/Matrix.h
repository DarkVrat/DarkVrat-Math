#ifndef DVM_MATRIX_H
#define DVM_MATRIX_H

namespace DVM 
{

	//Не забудь про единичные матрицы и т.п.
	template<typename T, size_t C, size_t R>
	struct MatTemplate
	{
		static_assert(C != 0 && R != 0, "C and R must not be zero");

		T data[C * R];

		MatTemplate()
		{
			for (size_t i = 0; i < C * R; ++i)
					data[i] = T{};
		}

		MatTemplate(T diagonalValue)
		{
			static_assert(C == R, "Diagonal matrix requires square matrix");

			for (size_t i = 0; i < C; ++i)
				for (size_t j = 0; j < R; ++j)
					data[i * R + j] = (i == j) ? diagonalValue : T{};
		}

		MatTemplate(T initValues[C * R])
		{
			for (size_t i = 0; i < C * R; ++i)
				data[i] = initValues[i];
		}

		MatTemplate(T initValues[C][R])
		{
			for (size_t i = 0; i < C; ++i)
				for (size_t j = 0; j < R; ++j)
					data[i * R + j] = initValues[i][j];
		}

		template<typename... Args>
		MatTemplate(Args... args)
		{
			static_assert(sizeof...(Args) == C * R, "Number of arguments must match matrix size");

			T initValues[] = { args... };

			for (size_t i = 0; i < C * R; ++i)
				data[i] = initValues[i];

		}

		MatTemplate(const MatTemplate& right)
		{
			for (size_t i = 0; i < C * R; ++i)
				data[i] = right[i / R][i % R];
		}

		template<typename U>
		MatTemplate(U diagonalValue)
		{
			static_assert(C == R, "Diagonal matrix requires square matrix");

			for (size_t i = 0; i < C; ++i)
				for (size_t j = 0; j < R; ++j)
					data[i * R + j] = (i == j) ? static_cast<T>(diagonalValue) : T{};
		}

		template<typename U>
		MatTemplate(U initValues[C * R])
		{
			for (size_t i = 0; i < C * R; ++i)
				data[i] = static_cast<T>(initValues[i]);
		}

		template<typename U>
		MatTemplate(U initValues[C][R])
		{
			for (size_t i = 0; i < C; ++i)
				for (size_t j = 0; j < R; ++j)
					data[i * R + j] = static_cast<T>(initValues[i][j]);
		}

		template<typename U>
		MatTemplate(const MatTemplate<U, C, R>& right)
		{
			for (size_t i = 0; i < C * R; ++i)
				data[i] = static_cast<T>(right[i / R][i % R]);
		}

		MatTemplate& operator=(const MatTemplate& right)
		{
			if (this != &right)
				for (size_t i = 0; i < C * R; ++i)
					data[i] = right[i / R][i % R];

			return *this;
		}

		template<typename U>
		MatTemplate& operator=(const MatTemplate<U, C, R>& right)
		{
			if (this != &right)
				for (size_t i = 0; i < R * R; ++i)
					data[i] = static_cast<T>(right[i / R][i % R]);

			return *this;
		}

		~MatTemplate() {};

		constexpr size_t Size() const { return C*R; }

		inline			T* operator[](size_t index)			{ return &data[index * R]; }
		inline const	T* operator[](size_t index) const	{ return &data[index * R]; }
		inline			T& operator()(size_t i, size_t j)		{ return data[i * R + j]; }
		inline const	T& operator()(size_t i, size_t j) const	{ return data[i * R + j]; }

		MatTemplate& operator++();
		MatTemplate& operator--();
		const MatTemplate operator++(int);
		const MatTemplate operator--(int);

		//Composite statements of the MatTemplate class
		MatTemplate& operator*=(T value);
		MatTemplate& operator*=(const MatTemplate& value);
		MatTemplate& operator/=(T value);
		MatTemplate& operator/=(const MatTemplate& value);
		MatTemplate& operator+=(T value);
		MatTemplate& operator+=(const MatTemplate& value);
		MatTemplate& operator-=(T value);
		MatTemplate& operator-=(const MatTemplate& value);
	};

	using Mat2i = MatTemplate<int, 2, 2>;
	using Mat2c = MatTemplate<char, 2, 2>;
	using Mat2f = MatTemplate<float, 2, 2>;
	using Mat2d = MatTemplate<double, 2, 2>;
	using Mat2si = MatTemplate<short int, 2, 2>;
	using Mat2ld = MatTemplate<long double, 2, 2>;
	using Mat2ui = MatTemplate<unsigned int, 2, 2>;
	using Mat2uc = MatTemplate<unsigned char, 2, 2>;
	using Mat2lli = MatTemplate<long long int, 2, 2>;
	using Mat2usi = MatTemplate<unsigned short int, 2, 2>;
	using Mat2ulli = MatTemplate<unsigned long long int, 2, 2>;

	using Mat3i = MatTemplate<int, 3, 3>;
	using Mat3c = MatTemplate<char, 3, 3>;
	using Mat3f = MatTemplate<float, 3, 3>;
	using Mat3d = MatTemplate<double, 3, 3>;
	using Mat3si = MatTemplate<short int, 3, 3>;
	using Mat3ld = MatTemplate<long double, 3, 3>;
	using Mat3ui = MatTemplate<unsigned int, 3, 3>;
	using Mat3uc = MatTemplate<unsigned char, 3, 3>;
	using Mat3lli = MatTemplate<long long int, 3, 3>;
	using Mat3usi = MatTemplate<unsigned short int, 3, 3>;
	using Mat3ulli = MatTemplate<unsigned long long int, 3, 3>;

	using Mat4i = MatTemplate<int, 4, 4>;
	using Mat4c = MatTemplate<char, 4, 4>;
	using Mat4f = MatTemplate<float, 4, 4>;
	using Mat4d = MatTemplate<double, 4, 4>;
	using Mat4si = MatTemplate<short int, 4, 4>;
	using Mat4ld = MatTemplate<long double, 4, 4>;
	using Mat4ui = MatTemplate<unsigned int, 4, 4>;
	using Mat4uc = MatTemplate<unsigned char, 4, 4>;
	using Mat4lli = MatTemplate<long long int, 4, 4>;
	using Mat4usi = MatTemplate<unsigned short int, 4, 4>;
	using Mat4ulli = MatTemplate<unsigned long long int, 4, 4>;

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator++()
	{
		for (size_t i = 0; i < C * R; ++i)
			++data[i];

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator--()
	{
		for (size_t i = 0; i < C * R; ++i)
			--data[i];

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline const MatTemplate<T, C, R> MatTemplate<T, C, R>::operator++(int)
	{
		MatTemplate temp(*this);
		++(*this);
		return temp;
	}

	template<typename T, size_t C, size_t R>
	inline const MatTemplate<T, C, R> MatTemplate<T, C, R>::operator--(int)
	{
		MatTemplate temp(*this);
		--(*this);
		return temp;
	}

	//Composite statements of the MatTemplate class
	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator*=(T value)
	{
		for (size_t i = 0; i < C * R; ++i)
			data[i] *= value;

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator*=(const MatTemplate& value)
	{
		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				data[i * R + j] *= value[i][j];

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator/=(T value)
	{
		for (size_t i = 0; i < C * R; ++i)
				data[i] /= value;

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator/=(const MatTemplate& value)
	{
		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				data[i * R + j] /= value;

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator+=(T value)
	{
		for (size_t i = 0; i < C * R; ++i)
				data[i] += value;

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator+=(const MatTemplate& value)
	{
		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				data[i * R + j] += value[i][j];

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator-=(T value)
	{
		for (size_t i = 0; i < C * R; ++i)
				data[i] -= value;

		return *this;
	}

	template<typename T, size_t C, size_t R>
	inline MatTemplate<T, C, R>& MatTemplate<T, C, R>::operator-=(const MatTemplate& value)
	{
		for (size_t i = 0; i < C; ++i)
			for (size_t j = 0; j < R; ++j)
				data[i * R + j] -= value[i][j];

		return *this;
	}

	//External operators of the MatTemplate class
	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator*(MatTemplate<T, C, R> lhs, T rhs) 
	{
		lhs *= rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator*(T lhs, MatTemplate<T, C, R> rhs) 
	{
		rhs *= lhs;
		return rhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator*(MatTemplate<T, C, R> lhs, const MatTemplate<T, C, R>& rhs) 
	{
		lhs *= rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator/(MatTemplate<T, C, R> lhs, T rhs) 
	{
		lhs /= rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator/(MatTemplate<T, C, R> lhs, const MatTemplate<T, C, R>& rhs) 
	{
		lhs /= rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator+(MatTemplate<T, C, R> lhs, T rhs) 
	{
		lhs += rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator+(MatTemplate<T, C, R> lhs, const MatTemplate<T, C, R>& rhs) 
	{
		lhs += rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator-(MatTemplate<T, C, R> lhs, T rhs) 
	{
		lhs -= rhs;
		return lhs;
	}

	template<typename T, size_t C, size_t R>
	MatTemplate<T, C, R> operator-(MatTemplate<T, C, R> lhs, const MatTemplate<T, C, R>& rhs) 
	{
		lhs -= rhs;
		return lhs;
	}
}

#endif // !DVM_MATRIX_H
