#ifndef DVTL_UTILITY_H
#define DVTL_UTILITY_H

namespace DVTL
{
	template<typename T> struct Remove_reference { typedef T type; };
	template<typename T> struct Remove_reference<T&> { typedef T type; };
	template<typename T> struct Remove_reference<T&&> { typedef T type; };

	template<typename T> using Remove_reference_t = typename Remove_reference<T>::type;

	template<typename T> constexpr bool Is_lvalue_reference_v = false;
	template<typename T> constexpr bool Is_lvalue_reference_v<T&> = true;

	template<typename T> constexpr Remove_reference_t<T>&& Move(T&& obj) noexcept { return static_cast<Remove_reference_t<T>&&>(obj); }
	template<typename T> constexpr T&& Forward(Remove_reference_t<T>& obj) noexcept { return static_cast<T&&>(obj); }
	template<typename T> constexpr T&& Forward(Remove_reference_t<T>&& obj) noexcept
	{
		static_assert(!Is_lvalue_reference_v<T>, "bad forward call");
		return static_cast<T&&>(obj);
	}

	template <bool B, typename T = void>
	struct Enable_if {};

	template <typename T>
	struct Enable_if<true, T> {
		using type = T;
	};

	template <bool B, typename T = void>
	using Enable_if_t = typename Enable_if<B, T>::type;
}

#endif // !DVTL_UTILITY_H
