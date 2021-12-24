#pragma once

template <typename T>
constexpr vector2<T>::vector2(T x, T y) : x(x), y(y){};
template <typename T>
template <typename F>
constexpr vector2<T> vector2<T>::op(const T &value, const F &func)
{
    return vector2(func(this->x, value), func(this->y, value));
};
template <typename T>
template <typename F>
constexpr vector2<T> vector2<T>::op(const vector2<T> &b, const F &func)
{
    return vector2(func(this->x, b.x), func(this->y, b.y));
};
template <typename T>
constexpr vector2<T> vector2<T>::operator+(const T &value)
{
    return vector2(this->x + value, this->y + value);
};
template <typename T>
constexpr vector2<T> vector2<T>::operator+(const vector2<T> &b)
{
    return vector2<T>(this->x + b.x, this->y + b.y);
};
template <typename T>
constexpr vector2<T> vector2<T>::operator*(const T &value)
{
    return vector2(this->x * value, this->y * value);
};
template <typename T>
constexpr vector2<T> vector2<T>::operator*(const vector2<T> &b)
{
    return vector2(this->x * b.x, this->y * b.y);
};
template <typename T>
constexpr vector2<T> vector2<T>::operator%(const T &value)
{
    return vector2<T>(this->x % value, this->y % value);
};
template <typename T>
constexpr vector2<T> vector2<T>::operator%(const vector2<T> &b)
{
    return vector2<T>(this->x % b.x, this->y % b.y);
};
template <typename T>
constexpr bool vector2<T>::operator==(const vector2<T> &b)
{
    return this->x == b.x && this->y == b.y;
};
template <typename T>
constexpr std::ostream &operator<<(std::ostream &out, const vector2<T> &b)
{
    out << '(' << b.x << ", " << b.y << ')';
    return out;
}
