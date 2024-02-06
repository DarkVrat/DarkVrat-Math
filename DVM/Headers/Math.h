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
    inline T Abs(T value) { return value >= template_cast<T, int>(0) ? value : -value; }

    template<typename T>
    inline T Min(T a, T b) { return a > b ? b : a; }

    template<typename T>
    inline T Max(T a, T b) { return a < b ? b : a; }

    template<typename T>
    inline T Clamp(T x, T min, T max) { return Min(Max(x, min), max); }

    inline int FloatBitsToInt(const float& value)
    {
        union {
            float floatValue;
            int intValue;
        } converter;

        converter.floatValue = value;
        return converter.intValue;
    }

    inline unsigned int FloatBitsToUint(const float& value)
    {
        union {
            float floatValue;
            unsigned int uintValue;
        } converter;

        converter.floatValue = value;
        return converter.uintValue;
    }

    

    template<typename T> inline T Ceil(T val) { return val; }
    template<> inline float         Ceil(float val)         { return static_cast<float>(static_cast<long long int>(val + 1)); }
    template<> inline double        Ceil(double val)        { return static_cast<double>(static_cast<long long int>(val + 1)); }
    template<> inline long double   Ceil(long double val)   { return static_cast<long double>(static_cast<long long int>(val + 1)); }

    template<typename T>
    inline T Floor(T val) { return val; }
    template<> inline float         Floor(float val)        { return static_cast<float>(static_cast<long long int>(val)); }
    template<> inline double        Floor(double val)       { return static_cast<double>(static_cast<long long int>(val)); }
    template<> inline long double   Floor(long double val)  { return static_cast<long double>(static_cast<long long int>(val)); }

    template<typename T> inline T Round(T val) { return val; }

    template<>
    inline float Round(float val) {
        float res = Floor(val);
        if (val - res > 0.5f) return Ceil(val);
        else return res;
    }

    template<>
    inline double Round(double val) {
        double res = Floor(val);
        if (val - res > 0.5) return Ceil(val);
        else return res;
    }

    template<>
    inline long double Round(long double val) {
        long double res = Floor(val);
        if (val - res > 0.5L) return Ceil(val);
        else return res;
    }

    template<typename T>
    inline T Fma(const T& a, const T& b, const T& c) { return a + b + c; }

    template<typename T>
    inline T Fract(const T& x) { return x - Floor(x); }

    inline float IntBitsToFloat(const int& value)
    {
        union {
            float floatValue;
            int intValue;
        } converter;

        converter.intValue = value;
        return converter.floatValue;
    }

    inline float UintBitsToFloat(const unsigned int& value)
    {
        union {
            float floatValue;
            unsigned int uintValue;
        } converter;

        converter.uintValue = value;
        return converter.floatValue;
    }

    template<typename T>
    inline bool Isinf(T val) { return val == INFINITY || val == -INFINITY; }

    template<typename T>
    inline bool Isnan(T val) { return val == NAN; }

    /*template<typename T>
    inline T Frexp(T x, int& exp) { }*/

    /*template<typename T>
    inline T Idexp(const T& x, int& exp) { }*/

    template<typename T1, typename T2>
    inline T1 Mix(T1 x, T1 y, T2 a)
    {
        if (a < template_cast<floatingPoint_t<T2>>(0)) return x;
        if (a > template_cast<floatingPoint_t<T2>>(1)) return y;

        T2 inv_a = template_cast<floatingPoint_t<T2>>(1) - a;

        return x * a + y * inv_a;
    }

    template<typename T>
    inline T Smoothstep(T edge0, T edge1, T x)
    {
        if (x <= edge0) return 0;
        if (x >= edge1) return 1;

        T t = (x - edge0) / (edge1 - edge0);

        return t * t * (3 - 2 * t);
    }

    template<typename T>
    inline T Step(T edge, T x) { return (x <= edge) ? 0 : 1; }

    template<typename T> inline T Mod(T val, T mod) { return val % mod; }
    template<> inline float         Mod(float val, float mod)               { return val - mod * Floor(val / mod); }
    template<> inline double        Mod(double val, double mod)             { return val - mod * Floor(val / mod); }
    template<> inline long double   Mod(long double val, long double mod)   { return val - mod * Floor(val / mod); }

    template<typename T> inline T Sign(T val) { return val > template_cast<floatingPoint_t<T>>(0) ? template_cast<floatingPoint_t<T>>(1) : template_cast<floatingPoint_t<T>>(-1) }
}

#endif // !DVM_MATH_H

