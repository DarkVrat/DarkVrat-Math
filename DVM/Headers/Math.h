#ifndef DVM_MATH_H
#define DVM_MATH_H

#include<iostream>

namespace DVM 
{
    template<typename T, typename U>
    constexpr T template_cast(U value) { return static_cast<T>(value); }

    template<typename T>    constexpr T             getEpsilon()                { return template_cast<T>(0); }
    template<>              constexpr float         getEpsilon<float>()         { return 0.0000'001f; }
    template<>              constexpr double        getEpsilon<double>()        { return 0.0000'0000'0000'0001; }
    template<>              constexpr long double   getEpsilon<long double>()   { return 0.0000'0000'0000'0001L; }

    template<typename T>    struct floatingPoint                {using type = float;};
    template<>              struct floatingPoint<double>        { using type = double; };
    template<>              struct floatingPoint<long double>   { using type = long double; };

    template<typename T> using floatingPoint_t = typename floatingPoint<T>::type;

    template <typename T>
    constexpr T Sqrt(T value) {
        if (value < template_cast<T>(0)) return template_cast<T>(0);
        if (value < template_cast<T>(1)) return template_cast<T>(1) / Sqrt(template_cast<T>(1) / value);

        T result = value;
        T epsilon = getEpsilon<T>()*value;
        floatingPoint_t<T> half = template_cast<floatingPoint_t<T>>(0.5L);

        for (int i = 0; i<520 && (result * result - value) > epsilon; ++i)
            result = static_cast<T>(half * static_cast<floatingPoint_t<T>>((result + value / result)));

        return result;
    }

    template<typename T>
    T Abs(T value) { return value < template_cast<T, int>(0) ? -value : value; }

}

#endif // !DVM_MATH_H

