#ifndef DVM_MATH_H
#define DVM_MATH_H

#include<iostream>

namespace DVM 
{
    template<typename T, typename U>
    constexpr T template_cast(U value) { return static_cast<T>(value); }

    template<typename T>    constexpr T             getEpsilon()                { return template_cast<T>(0); }
    template<>              constexpr float         getEpsilon<float>()         { return 0.0000'01f; }
    template<>              constexpr double        getEpsilon<double>()        { return 0.0000'0000'0000'01; }
    template<>              constexpr long double   getEpsilon<long double>()   { return 0.0000'0000'0000'01L; }

    template<typename T>    constexpr T             getE() { return template_cast<T>(2); }
    template<>              constexpr float         getE<float>() { return 2.7182'8f; }
    template<>              constexpr double        getE<double>() { return 2.7182'8182'8459'045; }
    template<>              constexpr long double   getE<long double>() { return 2.7182'8182'8459'045L; }

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
    constexpr T Abs(T value) { return value >= template_cast<T, int>(0) ? value : -value; }

    template<typename T>
    constexpr T Min(T a, T b) { return a > b ? b : a; }

    template<typename T>
    constexpr T Max(T a, T b) { return a < b ? b : a; }

    template<typename T>
    constexpr T Clamp(T x, T min, T max) { return Min(Max(x, min), max); }

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

    template<typename T> constexpr T Ceil(T val) { return val; }
    template<> constexpr float         Ceil(float val)         { return static_cast<float>(static_cast<long long int>(val + 1)); }
    template<> constexpr double        Ceil(double val)        { return static_cast<double>(static_cast<long long int>(val + 1)); }
    template<> constexpr long double   Ceil(long double val)   { return static_cast<long double>(static_cast<long long int>(val + 1)); }

    template<typename T> constexpr T Floor(T val) { return val; }
    template<> constexpr float         Floor(float val)        { return static_cast<float>(static_cast<long long int>(val)); }
    template<> constexpr double        Floor(double val)       { return static_cast<double>(static_cast<long long int>(val)); }
    template<> constexpr long double   Floor(long double val)  { return static_cast<long double>(static_cast<long long int>(val)); }

    template<typename T> constexpr T Round(T val) { return val; }

    template<>
    constexpr float Round(float val) {
        float res = Floor(val);
        if (val - res > 0.5f) return Ceil(val);
        else return res;
    }

    template<>
    constexpr double Round(double val) {
        double res = Floor(val);
        if (val - res > 0.5) return Ceil(val);
        else return res;
    }

    template<>
    constexpr long double Round(long double val) {
        long double res = Floor(val);
        if (val - res > 0.5L) return Ceil(val);
        else return res;
    }

    template<typename T>
    constexpr T Fma(const T& a, const T& b, const T& c) { return a + b + c; }

    template<typename T>
    constexpr T Fract(const T& x) { return x - Floor(x); }

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
    constexpr bool Isinf(T val) { return val == INFINITY || val == -INFINITY; }

    template<typename T>
    constexpr bool Isnan(T val) { return val == NAN; }

    template<typename T1, typename T2>
    constexpr T1 Mix(T1 x, T1 y, T2 a)
    {
        if (a < template_cast<floatingPoint_t<T2>>(0)) return x;
        if (a > template_cast<floatingPoint_t<T2>>(1)) return y;

        T2 inv_a = template_cast<floatingPoint_t<T2>>(1) - a;

        return x * a + y * inv_a;
    }

    template<typename T>
    constexpr T Smoothstep(T edge0, T edge1, T x)
    {
        if (x <= edge0) return 0;
        if (x >= edge1) return 1;

        T t = (x - edge0) / (edge1 - edge0);

        return t * t * (3 - 2 * t);
    }

    template<typename T>
    constexpr T Step(T edge, T x) { return (x <= edge) ? 0 : 1; }

    template<typename T> constexpr T Mod(T val, T mod) { return val % mod; }
    template<> constexpr float         Mod(float val, float mod)               { return val - mod * Floor(val / mod); }
    template<> constexpr double        Mod(double val, double mod)             { return val - mod * Floor(val / mod); }
    template<> constexpr long double   Mod(long double val, long double mod)   { return val - mod * Floor(val / mod); }

    template<typename T> constexpr T Sign(T val) { return val > template_cast<floatingPoint_t<T>>(0) ? template_cast<floatingPoint_t<T>>(1) : template_cast<floatingPoint_t<T>>(-1); }

    template<typename T>
    constexpr T Exp(T x)
    {
        T result = 1;
        T term = 1;

        for (int n = 1; !Isinf(result); n++)
        {
            term *= x / n;
            result += term;

            if (term == 0)
                break;
        }

        return result;
    }

    template<typename T>
    constexpr T Exp2(T x)
    {
        if (x < 0)
            return 0;

        T result = 1;
        for (T i = 0; i < x; ++i)
        {
            result *= 2;
        }

        return result;
    }

    template<>constexpr float          Exp2(float x)       { const float ln2 = 0.69314718f; return Exp(x * ln2);}
    template<>constexpr double         Exp2(double x)      { const double ln2 = 0.693147180559945; return Exp(x * ln2);}
    template<>constexpr long double    Exp2(long double x) { const  double ln2 = 0.693147180559945L; return Exp(x * ln2);}

    template<typename T>
    constexpr T Inversesqrt(T x) { return template_cast<T>(1) / Sqrt(x); }

    template<typename T>
    constexpr T Log(T x)
    {
        constexpr T E = getE<T>();

        if (x <= 0) return template_cast<T>(-1);

        if (x < E)
        {
            T res = template_cast<T>(0);

            while (x < E) {
                x *= E;
                res += template_cast<T>(1);
            }

            return Log(x) - res;
        }

        if (x > E * E)
        {
            T res = template_cast<T>(0);

            while (x > E * E) {
                x /= E;
                res += template_cast<T>(1);
            }

            return Log(x) + res;
        }

        T result = 0;
        T next_term = (x - 1) / (x + 1);
        T term_squared = next_term * next_term;
        T denom = 1;

        for (int i = 1; i <= 100; ++i) {
            result += next_term / denom;
            next_term *= term_squared;
            denom += 2;
        }

        result *= 2;

        return result;
    }

    template<typename T>
    constexpr T Log2(T x) 
    {
        constexpr floatingPoint_t<T> divider = Log(template_cast<floatingPoint_t<T>>(2));
        return template_cast<T>(Log<floatingPoint_t<T>>(template_cast<floatingPoint_t<T>>(x)) / divider);
    }

    template<typename T, typename U>
    constexpr T Pow(T base, U exp) 
    {
        if (exp == 0) return template_cast<T>(1);
        else if (exp < 0)
            return  template_cast<T>(1) / Pow(base, -exp);
        else
        {
            T result = 1;
            while (exp > 0)
            {
                result *= base;
                --exp;
            }
            return result;
        }
        return 0;
    }

    template<typename T>
    constexpr float Pow(T base, float exp)
    {
        if (exp == 0.f) return 1.f;
        float result = Exp(exp * Log(static_cast<float>(base)));
        return result;
    }

    template<typename T>
    constexpr double Pow(T base, double exp)
    {
        if (exp == 0.) return 1.;
        double result = Exp(exp * Log(static_cast<double>(base)));
        return result;
    }

    template<typename T>
    constexpr long double Pow(T base, long double exp)
    {
        if (exp == 0.L) return 1.L;
        long double result = Exp(exp * Log(static_cast<long double>(base)));
        return result;
    }
        
    template<typename T>
    constexpr T Frexp(T x, int& exp)
    {
        if (x == 0) {
            exp = 0;
            return x;
        }

        exp = static_cast<int>(Log2(Abs(x))) + 1;

        if (Abs(x) >= 0.5 && Abs(x) < 1) 
            exp--;

        T scaledValue = x * Pow(2, -exp);

        return scaledValue;
    }

    template<typename T>
    constexpr T Idexp(const T& x, int& exp)
    {
        int oldExp;
        T fraction = Frexp(x, oldExp);

        exp = oldExp + exp;

        T result = fraction * Pow(2, exp);

        return result;
    }
}

#endif // !DVM_MATH_H

