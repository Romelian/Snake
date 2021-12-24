#pragma once
#include <iostream>

template <typename T>
struct vector2
{
    T x;
    T y;
    constexpr vector2(T x, T y);
    template <typename F>
    constexpr vector2 op(const T &value, const F &func);
    template <typename F>
    constexpr vector2 op(const vector2 &b, const F &func);
    constexpr vector2 operator+(const T &value);
    constexpr vector2 operator+(const vector2 &b);
    constexpr vector2 operator*(const T &value);
    constexpr vector2 operator*(const vector2 &b);
    constexpr vector2 operator%(const T &value);
    constexpr vector2 operator%(const vector2 &b);
    constexpr bool operator==(const vector2 &b);
    template <typename F>
    constexpr friend std::ostream &operator<<(std::ostream &out, const vector2<F> &b);
};

#include "vector2.tpp"