#ifndef DVM_VECTOR_H
#define DVM_VECTOR_H

#include "Utility.h"
#include "Math.h"

namespace DVM
{
	template<typename T> struct S_X { T x; };
	template<typename T> struct S_XY { T x, y; };
	template<typename T> struct S_XYZ { T x, y, z; };
	template<typename T> struct S_XYZW { T x, y, z, w; };

	template<typename T1, typename T2, typename T3, typename T4, size_t>	struct Swich_N { using type = T4; };
	template<typename T1, typename T2, typename T3, typename T4>			struct Swich_N<T1, T2, T3, T4, 1> { using type = T1; };
	template<typename T1, typename T2, typename T3, typename T4>			struct Swich_N<T1, T2, T3, T4, 2> { using type = T2; };
	template<typename T1, typename T2, typename T3, typename T4>			struct Swich_N<T1, T2, T3, T4, 3> { using type = T3; };
	template<typename T1, typename T2, typename T3, typename T4, size_t N>	using  Swich_N_type = typename Swich_N<T1, T2, T3, T4, N>::type;

	template<typename T, size_t N>
	struct VecTemplate
	{
		static_assert(N != 0, "N must not be zero");

		union 
		{
			T data[N];
			Swich_N_type<S_X<T>, S_XY<T>, S_XYZ<T>, S_XYZW<T>, N> Values;
		};
		
		VecTemplate()
		{
			for (size_t i = 0; i < N; ++i)
				data[i] = T{};
		}

		VecTemplate(T initValues[N])
		{
			for (size_t i = 0; i < N; ++i)
				data[i] = initValues[i];
		}

		template<typename... Args>
		VecTemplate(Args... args)
		{
			static_assert(sizeof...(Args) == N, "Number of arguments must match vector size");

			T initValues[] = { args... };

			for (size_t i = 0; i < N; ++i)
				data[i] = initValues[i];
		}

		VecTemplate(const VecTemplate& right)
		{
			for (size_t i = 0; i < N; ++i)
				data[i] = right[i];
		}

		template<typename U, size_t M>
		VecTemplate(const VecTemplate<U, M>& right)
		{
			size_t minSize = N < M ? N : M;

			for (size_t i = 0; i < minSize; ++i)
				data[i] = static_cast<T>(right[i]);

			for (size_t i = minSize; i < N; ++i)
				data[i] = T{};
		}

		template<typename U, size_t M, typename... Args>
		VecTemplate(const VecTemplate<U, M>& right, Args... args)
		{
			static_assert(sizeof...(Args) + M == N, "Number of arguments must match vector size");

			T initValues[] = { args... };

			for (size_t i = 0; i < M; ++i)
				data[i] = static_cast<T>(right[i]);

			for (size_t i = M; i < N; ++i)
				data[i] = initValues[i - M];
		}

		VecTemplate& operator=(const VecTemplate& right)
		{
			if (this != &right)
				for (size_t i = 0; i < N; ++i)
					data[i] = right[i];

			return *this;
		}

		template<typename U, size_t M>
		VecTemplate& operator=(const VecTemplate<U, M>& right)
		{
			if (this != &right)
			{
				size_t minSize = N < M ? N : M;

				for (size_t i = 0; i < minSize; ++i)
					data[i] = static_cast<T>(right[i]);

				for (size_t i = minSize; i < N; ++i)
					data[i] = T{};
			}
			return *this;
		}

		~VecTemplate() {};

		VecTemplate& operator++();
		VecTemplate& operator--();
		const VecTemplate operator++(int);
		const VecTemplate operator--(int);

		//Composite statements of the VecTemplate class
		VecTemplate& operator%=(T value);
		VecTemplate& operator%=(const VecTemplate& value);
		VecTemplate& operator*=(T value);
		VecTemplate& operator*=(const VecTemplate& value);
		VecTemplate& operator/=(T value);
		VecTemplate& operator/=(const VecTemplate& value);
		VecTemplate& operator+=(T value);
		VecTemplate& operator+=(const VecTemplate& value);
		VecTemplate& operator-=(T value);
		VecTemplate& operator-=(const VecTemplate& value);
	
		VecTemplate& operator<<=(int shift);
		VecTemplate& operator<<=(const VecTemplate<int, N>& shift);
		VecTemplate& operator>>=(int shift);
		VecTemplate& operator>>=(const VecTemplate<int, N>& shift);

		VecTemplate& operator^=(T value);
		VecTemplate& operator^=(const VecTemplate& value);
		VecTemplate& operator|=(T value);
		VecTemplate& operator|=(const VecTemplate& value);
		VecTemplate& operator&=(T value);
		VecTemplate& operator&=(const VecTemplate& value);

		constexpr size_t Size() const { return N; }

		inline			T& operator[](size_t index)			{ return data[index]; }
		inline const	T& operator[](size_t index) const	{ return data[index]; }

		inline floatingPoint_t<T> length() const;
	};

	template<typename T, size_t N>
	inline floatingPoint_t<T> VecTemplate<T, N>::length() const
	{
		floatingPoint_t<T> sum_of_squares = 0;
		for (size_t i = 0; i < N; i++)
			sum_of_squares += data[i] * data[i];
		return Sqrt(sum_of_squares);
	}

	using Vec2i		= VecTemplate<int, 2>;
	using Vec2c		= VecTemplate<char, 2>;
	using Vec2f		= VecTemplate<float, 2>;
	using Vec2d		= VecTemplate<double, 2>;
	using Vec2si	= VecTemplate<short int, 2>;
	using Vec2ld	= VecTemplate<long double, 2>;
	using Vec2ui	= VecTemplate<unsigned int, 2>;
	using Vec2uc	= VecTemplate<unsigned char, 2>;
	using Vec2lli	= VecTemplate<long long int, 2>;
	using Vec2usi	= VecTemplate<unsigned short int, 2>;
	using Vec2ulli	= VecTemplate<unsigned long long int, 2>;

	using Vec3i		= VecTemplate<int, 3>;
	using Vec3c		= VecTemplate<char, 3>;
	using Vec3f		= VecTemplate<float, 3>;
	using Vec3d		= VecTemplate<double, 3>;
	using Vec3si	= VecTemplate<short int, 3>;
	using Vec3ld	= VecTemplate<long double, 3>;
	using Vec3ui	= VecTemplate<unsigned int, 3>;
	using Vec3uc	= VecTemplate<unsigned char, 3>;
	using Vec3lli	= VecTemplate<long long int, 3>;
	using Vec3usi	= VecTemplate<unsigned short int, 3>;
	using Vec3ulli	= VecTemplate<unsigned long long int, 3>;

	using Vec4i		= VecTemplate<int, 4>;
	using Vec4c		= VecTemplate<char, 4>;
	using Vec4f		= VecTemplate<float, 4>;
	using Vec4d		= VecTemplate<double, 4>;
	using Vec4si	= VecTemplate<short int, 4>;
	using Vec4ld	= VecTemplate<long double, 4>;
	using Vec4ui	= VecTemplate<unsigned int, 4>;
	using Vec4uc	= VecTemplate<unsigned char, 4>;
	using Vec4lli	= VecTemplate<long long int, 4>;
	using Vec4usi	= VecTemplate<unsigned short int, 4>;
	using Vec4ulli	= VecTemplate<unsigned long long int, 4>;

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator++()
	{
		for (size_t i = 0; i < N; i++)
			++data[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator--()
	{
		for (size_t i = 0; i < N; i++)
			--data[i];
		return *this;
	}

	template<typename T, size_t N>
	inline const VecTemplate<T, N> VecTemplate<T, N>::operator++(int)
	{
		VecTemplate<T, N> result(*this);
		++(*this);
		return result;
	}

	template<typename T, size_t N>
	inline const VecTemplate<T, N> VecTemplate<T, N>::operator--(int)
	{
		VecTemplate<T, N> result(*this);
		--(*this);
		return result;
	}

	//Composite statements of the VecTemplate class
	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator%=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] %= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator%=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] %= value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator*=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] *= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator*=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] *= value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator/=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] /= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator/=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] /= value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator+=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] += value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator+=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] += value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator-=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] -= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator-=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] -= value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator<<=(int shift)
	{
		for (size_t i = 0; i < N; i++)
			data[i] <<= shift;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator<<=(const VecTemplate<int, N>& shift)
	{
		for (size_t i = 0; i < N; i++)
			data[i] <<= shift[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator>>=(int shift)
	{
		for (size_t i = 0; i < N; i++)
			data[i] >>= shift;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator>>=(const VecTemplate<int, N>& shift)
	{
		for (size_t i = 0; i < N; i++)
			data[i] >>= shift[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator^=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] ^= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator^=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] ^= value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator|=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] |= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator|=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] |= value[i];
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator&=(T value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] &= value;
		return *this;
	}

	template<typename T, size_t N>
	inline VecTemplate<T, N>& VecTemplate<T, N>::operator&=(const VecTemplate& value)
	{
		for (size_t i = 0; i < N; i++)
			data[i] &= value[i];
		return *this;
	}

	//External operators of the VecTemplate class
	template <typename T, size_t N>
	VecTemplate<T, N> operator%(VecTemplate<T, N> lhs, T rhs) {
		lhs %= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator%(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs %= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator*(VecTemplate<T, N> lhs, T rhs) {
		lhs *= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator*(T lhs, VecTemplate<T, N> rhs) {
		rhs *= lhs;
		return rhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator*(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs *= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator/(VecTemplate<T, N> lhs, T rhs) {
		lhs /= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator/(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs /= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator+(VecTemplate<T, N> lhs, T rhs) {
		lhs += rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator+(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs += rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator-(VecTemplate<T, N> lhs, T rhs) {
		lhs -= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator-(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs -= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator<<(VecTemplate<T, N> lhs, int rhs) {
		lhs <<= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator<<(VecTemplate<T, N> lhs, const VecTemplate<int, N>& rhs) {
		lhs <<= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator>>(VecTemplate<T, N> lhs, int rhs) {
		lhs >>= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator>>(VecTemplate<T, N> lhs, const VecTemplate<int, N>& rhs) {
		lhs >>= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator^(VecTemplate<T, N> lhs, T rhs) {
		lhs ^= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator^(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs ^= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator|(VecTemplate<T, N> lhs, T rhs) {
		lhs |= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator|(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs |= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator&(VecTemplate<T, N> lhs, T rhs) {
		lhs &= rhs;
		return lhs;
	}

	template <typename T, size_t N>
	VecTemplate<T, N> operator&(VecTemplate<T, N> lhs, const VecTemplate<T, N>& rhs) {
		lhs &= rhs;
		return lhs;
	}

}



#endif // !DVM_VECTOR_H

